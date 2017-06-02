#include "Game.h"
#include "vendor/easylogging++.h"

Game::Game(NetworkManager *networkManager, bool isServer) : world(new GameWorld(this)),
                                                            networkManager(networkManager), isServer(isServer)
{
    world->addNetworkManager(networkManager);
}

void Game::start()
{
    mainWindow.create(sf::VideoMode(width, height), "Tanks");
    mainWindow.setFramerateLimit(fps);

    if (isOnServer())
        mainWindow.setTitle("Server");
    else
        mainWindow.setTitle("Client");

    KeyboardTank *localPlayer = new KeyboardTank(world);
    RemoteTank *opponent = new RemoteTank(world);

    Terrain *terrain;
    if (isOnServer())
    {
        int seed = (int) time(NULL);
        terrain = new Terrain(world, seed);
        Command command("terrain", 1);
        command.addArgument(seed, 0);

        networkManager->send(command);
    } else
    {
        Command command;
        while (!networkManager->receive(command) || command.getName() != "terrain")
        {
            sf::sleep(sf::seconds(1.0f / fps));
        }
        terrain = new Terrain(world, command.getArgument(0));
    }

    world->setOnServer(isOnServer());
    world->setWindow(&mainWindow);

    world->addPlayer(localPlayer);
    world->addOpponent(opponent);

    terrain->setPosition(0, height / 2);
    world->addTerrain(terrain);

    if (isOnServer())
    {
        opponent->setPositionX(distance);
        localPlayer->setPosition(width - distance, 0);
    } else
    {
        opponent->setPositionX(width - distance);
        localPlayer->setPosition(distance, 0);
    }

    gameState = Game::Playing;
    while (mainWindow.isOpen())
    {
        switch (gameState)
        {
            case Game::Playing:
                gameLoop();
                break;
            case Game::Ended:
                gameOver();
        }
    }
    mainWindow.close();
}

void Game::gameLoop()
{
    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mainWindow.close();
    }

    while (accumulator > ups)
    {
        Command command;
        if (networkManager->receive(command))
        {
            if (command.getName() == "move")
                world->getOpponent()->setPositionX(command.getArgument(0));
            else if (command.getName() == "rotate")
                world->getOpponent()->setGunRotation(command.getArgument(0));
            else if (command.getName() == "fire")
                world->getOpponent()->fire(command.getArgument(0), command.getArgument(1));
            else if (command.getName() == "gameOver")
                over(false);
        }

        accumulator -= ups;
        world->updateAll(ups);
    }

    mainWindow.clear(sf::Color::White);
    world->drawAll(mainWindow);
    mainWindow.display();

    accumulator += clock.restart();
}

Game::~Game()
{
    delete world;
    delete networkManager;
}

bool Game::isOnServer()
{
    return isServer;
}

void Game::over(bool localPlayerIsWinner)
{
    this->localPlayerIsWinner = localPlayerIsWinner;
    gameState = Ended;
}

void Game::gameOver()
{
    mainWindow.clear(sf::Color::White);

    sf::Text text;
    text.setColor(sf::Color::Black);

    if (localPlayerIsWinner)
        text.setString("You're winner!");
    else
        text.setString("Sorry, but you lose.");

    sf::Font font;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << static_cast<std::string> (text.getString());
    } else
    {
        text.setFont(font);
        text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
        text.setPosition(width / 2, height / 4);

        mainWindow.draw(text);
        mainWindow.display();
    }

    sf::Event event;

    while (mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed ||
            event.type == sf::Event::MouseButtonPressed)
            mainWindow.close();
    }
}
