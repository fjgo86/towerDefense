#include <iostream>

#include "MainMenuManager.h"

#include "../Game.h"

MainMenuManager::MainMenuManager() {

    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");

    this->initMusic();
    this->initMenu();
}

void loadTextures() {

    gGame._textureManager->loadFromFile("logoMenu", "media/logos/logo.png");
}

void MainMenuManager::initMusic() {

    if (!backgroundMusic.openFromFile("media/music/mainMenu.flac"))
        std::cout << "Error cargando la musica de fondo." << std::endl;
    backgroundMusic.setVolume(0.5f);
    backgroundMusic.setLoop(true);

    if (backgroundMusic.getStatus() == backgroundMusic.Stopped)
        backgroundMusic.play();
    //std::cout << "Reproduciendo musica" << std::endl;
}

void MainMenuManager::initMenu() {

    loadTextures();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));

    for (int i = 0; i < Menu_QTY; i++) {
        
            botonesMenu[i] = BotonMenu(
            Menu_Strings[i],
            500,
            500,
            50.f,
            50.f);
    }
}

void MainMenuManager::handleInput() {
    sf::Event event;
    while (gGame._gameWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                gGame._gameWindow.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        gGame._gameWindow.close();
                        break;
                    case sf::Keyboard::Space:        // pulsar SPACE para pasar al juego
                        if (backgroundMusic.getStatus() == backgroundMusic.Playing)
                            backgroundMusic.stop();
                        gGame._statesManager->setEstadoActual("game");
                        break;
                    case sf::Keyboard::N:        // pulsar N para iniciar una nueva partida
                        if (backgroundMusic.getStatus() == backgroundMusic.Playing)
                            backgroundMusic.stop();
                        gGame._statesManager->newGame(true);
                        break;
                    default:
                        break;
                }
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
					case sf::Mouse::Left:
						break;
					default:
						break;
                }
                break;
            case sf::Event::MouseMoved: 
                break;
			default:
				break;
        }
    }
}

void MainMenuManager::onTick() {

    this->update();

    gGame._gameWindow.draw(logo);
    //gGame._gameWindow.draw(botonMusica);

    for each (BotonMenu boton in botonesMenu) {
        
        boton.setPosition(500.f, 500.f);
        gGame._gameWindow.draw(boton);
        std::cout << "Boton X: " << boton.getPosition().x << std::endl;
        std::cout << "Boton Y: " << boton.getPosition().y << std::endl;
    }
}

void MainMenuManager::update() {

    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01f) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);
}

MainMenuManager::~MainMenuManager() {
    backgroundMusic.stop();
}