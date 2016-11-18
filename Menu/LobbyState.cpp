#include <iostream>
#include <cmath>

#include "LobbyState.h"

#include "../Game.h"

LobbyState::LobbyState() {

    // Iniciamos la vista actual a la del login.
    _vistaActual = &loginView;

    // Iniciamos elementos visuales de la pantalla de login.
    this->initLogin();
}

// Carga las texturas y shaders necesarios.
void LobbyState::loadBackgroundTextures() {

    gGame._textureManager->loadFromFile("logoMenu", "media/logos/logo.png");
    gGame._textureManager->loadFromFile("background", "media/background.jpg");

    if (sf::Shader::isAvailable()) {

        if (!backgroundShader.loadFromFile("media/shaders/clouds.frag", sf::Shader::Fragment)) {

            std::cout << "Error cargando el shader de fondo en el menu principal." << std::endl;
        }
        else {

            backgroundShader.setUniform("resolution", sf::Glsl::Vec2(gGame._screenWidth, gGame._screenHeight));
            background.setTexture(*gGame._textureManager->getRef("background"));
        }
    }
}

// Posicionamiento de los elementos en el fondo de pantalla
void LobbyState::initLogin() {

    // Carga de texturas
    this->loadBackgroundTextures();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));
}

void LobbyState::onTick() {

    // Recupera la vista por defecto (la de esta clase) y "incrusta" los elementos en ella
    gGame._gameWindow.setView(gGame._gameWindow.getDefaultView());
    gGame._gameWindow.draw(background, &backgroundShader);
    gGame._gameWindow.draw(logo);

    loginView.onTick();
    menuView.onTick();
    //_vistaActual->onTick();
}

void LobbyState::handleInput() {

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
                    case sf::Keyboard::Return:
                        moveLobby();
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

        _vistaActual->handleInput(event);
    }

    // Llamada al método para realizar cambios,
    // con una referencia a los eventos por si fuera necesario
    this->update();
}

void LobbyState::moveLobby() {

    if (_xDistanceMenu == 0) {

        _moveLobby = true;
        _vistaActual = &menuView;
    }   
}

void LobbyState::update() {

    // Este parametro controla la velocidad de movimiento de las nubes
    backgroundShader.setUniform("time", _backgroundUniform += 0.5f);

    /*
    Transformaciones visuales en el logo
    */
    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01f) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);

    // Mover el login
    if (_moveLobby) {

        _xDistanceMenu = (gGame._screenWidth * 1.5) - loginView.getCenter().x;
        std::cout << "xDistanceMenu: " << _xDistanceMenu << std::endl;

        if (_xDistanceMenu > 0.01f) {
            loginView.move(_xDistanceMenu * _easingMenu, 0);
            menuView.move(_xDistanceMenu * _easingMenu, 0);
        }
        else {
         
        std::cout << "Animacion Finalizada" << std::endl;
        _moveLobby = false;
        }
    }
}

LobbyState::~LobbyState() {
}
