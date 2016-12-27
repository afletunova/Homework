#include "Game.h"
#include "Tank.h"

void Game::start() {

    mainWindow.create(sf::VideoMode(width, height), "Tanks");

    Tank *player = new Tank(world);
    player->setPosition(width / 2, height / 2);

    Terrain *terrain = new Terrain(world);
    terrain->setPosition(0, height / 2);

    world->addPlayer(player);
    world->setCamera(height);
    world->addTerrain(terrain);

    gameState = Game::Playing;
    while (mainWindow.isOpen()) {
        gameLoop();
    }

    mainWindow.close();
}

void Game::gameLoop() {
    sf::Event event;
    while (mainWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mainWindow.close();
        if (event.type == sf::Event::LostFocus)
            gameState = Game::Paused;

        break;
    }
    switch (gameState) {
        case Game::Playing:

            while (accumulator > ups) {
                accumulator -= ups;
                world->updateAll(ups);
            }


            mainWindow.clear(sf::Color::White);
            world->drawAll(mainWindow);
            mainWindow.display();

            accumulator += clock.restart();
            break;


        case Game::Paused:
            if (event.type == sf::Event::GainedFocus)
                gameState = Game::Playing;
            break;

        default:
            break;
    }

}

Game::Game(): world(new GameWorld) {

}

Game::~Game() {
    delete world;
}


