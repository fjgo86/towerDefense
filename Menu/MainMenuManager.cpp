#include <iostream>

#include "MainMenuManager.h"

#include "../Game.h"

MainMenuManager::MainMenuManager() {

    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");

    this->initMusic();
    this->initMenu();
}

void MainMenuManager::loadTextures() {

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

    this->loadTextures();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));

    sf::Vector2f pos = sf::Vector2f(gGame._screenWidth * 0.05f, gGame._screenHeight * 0.9f);
    for (int i = Menu_QTY - 1; i >= 0; i--) {
            
            // Creamos los botones, obtenemos el tamaño del texto
            // una vez creados, y los posicionamos en relacion a esto
            botonesMenu[i] = BotonMenu(Menu_Strings[i], fuente);
            botonesMenu[i].setPosition(pos);
            botonesMenu[i].setType(i);
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
                        this->manageBackgroundMusic();
                        gGame._statesManager->setEstadoActual("game");
                        break;
                    case sf::Keyboard::N:        // pulsar N para iniciar una nueva partida
                        this->manageBackgroundMusic();
                        gGame._statesManager->newGame();
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

    // Llamada al método para realizar cambios,
    // con una referencia a los eventos por si fuera necesario
    this->update(event);
}

void MainMenuManager::onTick() {

    gGame._gameWindow.draw(logo);

    for (int i = 0; i < Menu_QTY; i++) {
        gGame._gameWindow.draw(botonesMenu[i]);
    }
}

void MainMenuManager::update(sf::Event &event) {

    /*
    Actualiza los estados de los botones
    */
    for (int i = 0; i < Menu_QTY; i++) {
        botonesMenu[i].update(event, gGame._gameWindow);
        
        if (botonesMenu[i].getState() == BotonMenu::state::clicked) {

            botonesMenu[i].setState(BotonMenu::state::normal);

            switch (botonesMenu[i].getType()) {
                case Nueva_Partida:
                    this->manageBackgroundMusic();
                    gGame._statesManager->newGame();
                    break;
                case Opciones:
                    std::cout << "TODO: Pasar a pantalla de opciones" << std::endl;
                    break;
                case Salir:
                    gGame._gameWindow.close();
                    break;
                default:
                    break;
            }
        }
    }

    /*
    Transformaciones visuales en el logo
    */
    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01f) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);
}

void MainMenuManager::manageBackgroundMusic() {

    // De momento solo para la musica.
    if (backgroundMusic.getStatus() == backgroundMusic.Playing)
        backgroundMusic.stop();
}

MainMenuManager::~MainMenuManager() {
    backgroundMusic.stop();
}