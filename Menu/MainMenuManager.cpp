#include <iostream>

#include "MainMenuManager.h"

#include "../Game.h"

MainMenuManager::MainMenuManager() {

    if (!backgroundMusic.openFromFile("media/music/mainMenu.flac"))
        std::cout << "Error cargando la musica de fondo." << std::endl;
    backgroundMusic.setVolume(20.0f);
    
    if (backgroundMusic.getStatus() == backgroundMusic.Stopped)
        backgroundMusic.play();
        //std::cout << "Reproduciendo musica" << std::endl;

    if (!logoTex.loadFromFile("media/logos/logo.png"))
        std::cout << "Error cargando la textura del logo." << std::endl;

    logo.setTexture(logoTex);
    logo.setPosition((float)(gGame._screenWidth / 2), (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));

    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");
    texto.setFont(fuente);
    texto.setPosition((float)(gGame._screenWidth / 2), (float)(gGame._screenWidth / 2)); // <--- Es correcto usar como Y Width en vez de Height ?
    texto.setString("PULSAR ESPACIO PARA CONTINUAR");
    texto.setOrigin(texto.getGlobalBounds().width / 2, texto.getGlobalBounds().height / 2);
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
                        gGame._statesManager->setEstadoActual(gGame._game);
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
    gGame._gameWindow.draw(texto);
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