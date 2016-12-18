#include "Game.h"

void Game::Start()
{
    if (gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024,720), "Tanks");


    player.load("image.png");
    player.setPosition((1024 / 2), 300);

    gameState = Game::Playing;
    while (mainWindow.isOpen())
    {
        gameLoop();
    }

    mainWindow.close();
}

void Game::gameLoop()
{
    sf::Event event;
    while (mainWindow.pollEvent(event))
    {
        switch (gameState)
        {
            case Game::Playing:
            {
                mainWindow.clear(sf::Color::White);
                mainWindow.draw(player);
                mainWindow.display();

                if (event.type == sf::Event::Closed)
                {
                    gameState = Game::Exiting;
                }
                break;
            }

            case Game::Exiting:
                mainWindow.close();
                break;

            default: break;
        }
    }
}

void Game::updatePlayer()
{

}

void Game::update()
{
    updatePlayer();
}

sf::RenderWindow Game::mainWindow;
Tank Game::player;
Game::GameState Game::gameState = Game::Uninitialized;