#include <iostream>
#include <cmath>

#include "LoginManager.h"

#include "../Game.h"

LoginManager::LoginManager() {

    this->setCenter((float)gGame._screenWidth / 2, (float)gGame._screenHeight / 2);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);
}

void LoginManager::handleInput(sf::Event &event) {

    //while (gGame._gameWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                gGame._gameWindow.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        gGame._gameWindow.close();
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
            default:
                break;
        }
    //}
}

void LoginManager::onTick() {

    // Vista con los botones del menu
    gGame._gameWindow.setView((*this));
    gGame._gameWindow.draw(_loginBox);
}

LoginManager::~LoginManager() {
}