#include "MainMenuManager.h"
#include <iostream>

MainMenuManager::MainMenuManager() {

    pGameStatesManager = new GameStatesManager();

    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");
    texto.setFont(fuente);
    texto.setPosition(gGame.iScreenWidth / 2, gGame.iScreenWidth / 2);
    texto.setString("PULSAR ESPACIO PARA CONTINUAR");
    texto.setOrigin(texto.getGlobalBounds().width / 2, texto.getGlobalBounds().height / 2);
}

void MainMenuManager::handleInput() {
    sf::Event event;
    while (gGame.pGameWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            gGame.pGameWindow.close();
            break;
        case sf::Event::KeyReleased: {
            switch (event.key.code) {
            case sf::Keyboard::Escape:
                gGame.pGameWindow.close();
                break;

            case sf::Keyboard::Space: {		// pulsar SPACE para pasar al juego
                
                pGameManager = new GameManager();
                gGame.pGameStatesManager->setEstadoActual(pGameManager);
                break;
            }

            default:
                break;
            }
        case sf::Event::MouseButtonPressed:
        {
            switch (event.mouseButton.button) {
            case sf::Mouse::Left:
                break;
            }
            break;
        }
        case sf::Event::MouseMoved:
        {
            break;
        }
        }
        }
    }
}

void MainMenuManager::onTick() {

    gGame.pGameWindow.draw(texto);
}

MainMenuManager::~MainMenuManager() {

    delete pGameManager;
}