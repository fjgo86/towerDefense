#include <iostream>
#include <cmath>

#include "LoginState.h"

#include "../Game.h"

LoginState::LoginState() {

    viewBackground = sf::View(sf::Vector2f(gGame._screenWidth / 2, gGame._screenHeight / 2),
        sf::Vector2f(gGame._screenWidth, gGame._screenHeight));

    viewLogin = sf::View(sf::Vector2f(gGame._screenWidth * -0.5, gGame._screenHeight / 2),
        sf::Vector2f(gGame._screenWidth, gGame._screenHeight));

    centerLobby.setRadius(10.f);
    centerLobby.setOrigin(centerLobby.getGlobalBounds().width / 2, centerLobby.getGlobalBounds().height / 2);
    centerLobby.setFillColor(sf::Color::Green);
    centerLobby.setPosition(viewLogin.getCenter());

    frameLobby = sf::RectangleShape(sf::Vector2f(gGame._screenWidth, gGame._screenHeight));
    frameLobby.setOrigin(frameLobby.getGlobalBounds().width / 2, frameLobby.getGlobalBounds().height / 2);
    frameLobby.setOutlineColor(sf::Color::Green);
    frameLobby.setOutlineThickness(1.f);
    frameLobby.setPosition(viewLogin.getCenter());
    frameLobby.setFillColor(sf::Color(0, 0, 0, 0));

    this->initLogin();
}

void LoginState::loadTextures() {

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

void LoginState::initLogin() {

    this->loadTextures();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));
}

void LoginState::moveToLobby() {

    viewLogin.move(1, 0);
}

void LoginState::onTick() {

    // Vista con el fondo y el logo
    gGame._gameWindow.setView(viewBackground);

    gGame._gameWindow.draw(background, &backgroundShader);
    gGame._gameWindow.draw(logo);

    // Vista con los botones del menu
    gGame._gameWindow.setView(viewLogin);

    gGame._gameWindow.draw(centerLobby);
    gGame._gameWindow.draw(frameLobby);
}

void LoginState::handleInput() {
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
            case sf::Keyboard::BackSpace:
                moveToLobby();
                break;
            default:
                break;
            }
            break;
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

    this->update(event);
}

void LoginState::update(sf::Event &event) {

    // Este parametro controla la velocidad de movimiento de las nubes
    backgroundShader.setUniform("time", t += 0.5f);

    // Mover el login
    if ((viewLogin.getCenter().x > -(gGame._screenWidth / 2)) && (viewLogin.getCenter().x < (gGame._screenWidth / 2))) {

        _xDistanceMenu = (gGame._screenWidth / 2) - viewLogin.getCenter().x;
        std::cout << "xDistanceMenu: " << _xDistanceMenu << std::endl;
        if (std::trunc(_xDistanceMenu) > 0) {
            viewLogin.move(_xDistanceMenu * _easingMenu, 0);
        }
        else {

            std::cout << "ejecutando else" << std::endl;
            gGame._statesManager->setEstadoActual("menu");
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

LoginState::~LoginState() {
}