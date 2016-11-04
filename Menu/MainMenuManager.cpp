#include <iostream>
#include "MainMenuManager.h"


MainMenuManager::MainMenuManager() {

    if (!backgroundMusic.openFromFile("media/music/mainMenu.flac"))
        std::cout << "Error cargando la musica de fondo" << std::endl;
    backgroundMusic.setVolume(20.0f);
    
    if (backgroundMusic.getStatus() == backgroundMusic.Stopped)
        backgroundMusic.play();
        //std::cout << "Reproduciendo musica" << std::endl;

    logoTex.loadFromFile("media/logos/logo.png");

    logo.setTexture(logoTex);
    logo.setPosition(gGame.iScreenWidth / 2, gGame.iScreenHeight * 0.2);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));

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

					case sf::Keyboard::Space:{		// pulsar SPACE para pasar al juego
						if (backgroundMusic.getStatus() == backgroundMusic.Playing)
							backgroundMusic.stop();
						pGameManager = new GameManager();
						gGame.pGameStatesManager->setEstadoActual(pGameManager);
						break;
					}

					default:
						break;
				}
			}
			case sf::Event::MouseButtonPressed: {
				switch (event.mouseButton.button) {
				case sf::Mouse::Left:
					break;
				}
				break;
			}
			case sf::Event::MouseMoved: {
				break;
			}
        }
    }
}

void MainMenuManager::onTick() {

    this->update();

    gGame.pGameWindow.draw(logo);
    gGame.pGameWindow.draw(texto);
}

void MainMenuManager::update() {

    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);
}

MainMenuManager::~MainMenuManager() {

    delete pGameManager;
    backgroundMusic.stop();
}