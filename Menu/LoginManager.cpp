#include <iostream>

#include "LoginManager.h"

#include "../Game.h"

LoginManager::LoginManager() {

    this->setCenter((float)gGame._screenWidth / 2, (float)gGame._screenHeight / 2);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    this->_loginBox.setOrigin(_loginBox.getGlobalBounds().width / 2, _loginBox.getGlobalBounds().height);
    this->_loginBox.move((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.9f);
}

void LoginManager::handleInput(sf::Event &event) {

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
                    _mousePos = sf::Mouse::getPosition(gGame._gameWindow);
                    this->handleLoginBoxEvents(_mousePos, 0);
                    break;
                default:
                    break;
                }
            break;
        case sf::Event::MouseMoved:            
            // Con vistas a hacer algun efecto al hacer hover sobre los elementos

            //_mousePos = sf::Mouse::getPosition(gGame._gameWindow);
            //this->handleLoginBoxEvents(_mousePos, 1);
            break;

        case sf::Event::TextEntered:
            this->handleLoginBoxEvents(sf::Vector2i(0, 0), 2, event.text.unicode);
		
        default:
            break;
    }
}

void LoginManager::handleLoginBoxEvents(sf::Vector2i pos, char type, sf::Uint32 c) {

    switch (type) {
        case 0:     // Click izquierdo
            
            if (_loginBox.getTextBoxUser().getGlobalBounds().contains((sf::Vector2f)pos)) {

                _loginBox.setFocusedComponent(LoginBox::MainComponents::TextBoxUser);
            }

            else if (_loginBox.getTextBoxPassword().getGlobalBounds().contains((sf::Vector2f)pos)) {

                _loginBox.setFocusedComponent(LoginBox::MainComponents::TextBoxPassword);
            }

            else if (_loginBox.getBotonConectar().getGlobalBounds().contains((sf::Vector2f)pos)) {

                _loginBox.setFocusedComponent(LoginBox::MainComponents::BotonConectar);
            }

            else {

                _loginBox.setFocusedComponent(LoginBox::MainComponents::MainComponentsQTY);
            }

            break;

        case 1:     // Movimiento de raton
            std::cout << "moved" << std::endl;
            break;

        case 2:
            std::cout << "tecla pulsada: " << c << std::endl;
            if (_loginBox._focusedTextBox != nullptr && (c < 128)) {

				/*
				XUN: Aqui es donde quiero diferenciar que textBox tiene el foco, para poder dibujar en el password asteriscos en lugar de la contrase�a
				*/

				switch (c) {

					case 8:		// Tecla BACKSPACE, para borrar el ultimo caracter
						_loginBox._focusedTextBox->setString(_loginBox._focusedTextBox->getString().substring(0, _loginBox._focusedTextBox->getString().getSize() - 1));
						break;
					case 27:	// Tecla ESCAPE, lo capturo para que no pinte un simbolo extra�o
						break;
					default:
						_loginBox._focusedTextBox->setString(_loginBox._focusedTextBox->getString() + c);
						break;
				}
            }

        default:
            break;
    }
}

void LoginManager::onTick() {

    // Vista con los botones del menu
    gGame._gameWindow.setView((*this));
    gGame._gameWindow.draw(_loginBox);
}

LoginManager::~LoginManager() {
}