#include "Game.h"
#include "KeyboardTank.h"
#include "vendor/easylogging++.h"

Game::Game(NetworkManager *networkManager, bool isServer) : world(new GameWorld(this)),
                                                            networkManager(networkManager), isServer(isServer)
{
    world->addNetworkManager(networkManager);
}

void Game::start()
{
    mainWindow.create(sf::VideoMode(width,height), "Tanks");
    mainWindow.setFramerateLimit(fps);

    if(isOnServer())
        mainWindow.setTitle("Server");
    else
        mainWindow.setTitle("Client");

    KeyboardTank *localPlayer = new KeyboardTank(world);
    RemoteTank *opponent = new RemoteTank(world);

    Terrain *terrain;
    Command command;
    if (isOnServer())
    {
        int seed = (int) time(NULL);
        terrain = new Terrain(world, seed);
        command.name = "terrain";
        command.argumentsCount = 1;
        command.arguments = new int[command.argumentsCount];
        command.arguments[0] = seed;
        networkManager->send(command);
    }
    else
    {
        while (!networkManager->receive(command) || command.name != "terrain")
        {
            sf::sleep(sf::seconds(1.0f / fps));
        }
        terrain = new Terrain(world, command.arguments[0]);
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
    }
    else
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
                mainWindow.close();
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
        break;
    }

    Command command;
    if (networkManager->receive(command))
    {
        if (command.name == "move")
            world->getOpponent()->setPositionX(command.arguments[0]);
        else if (command.name == "rotate")
            world->getOpponent()->setGunRotation(command.arguments[0]);
        else if (command.name == "fire")
            world->getOpponent()->fire(command.arguments[0], command.arguments[1]);
        else if (command.name == "gameOver")
            over(false);
    }

    while (accumulator > ups)
    {
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
    sf::Text text;
    text.setCharacterSize(height / 20);
    text.setColor(sf::Color::Black);

    if (localPlayerIsWinner)
        text.setString("You're winner!");
    else
        text.setString("Sorry, but you lose.");

    LOG(INFO) << (std::string) text.getString();

    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(width / 2, height / 4);

    mainWindow.draw(text);

    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
            mainWindow.close();
        break;
    }
}
