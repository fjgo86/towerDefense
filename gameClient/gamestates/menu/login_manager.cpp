#include <iostream>

#include "login_manager.h"
#include "state_lobby.h"

#include "../../game.h"

LoginManager::LoginManager() {

    this->setCenter((float)gGame._screenWidth / 2, (float)gGame._screenHeight / 2);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    this->_loginBox.setOrigin(_loginBox.getGlobalBounds().width / 2, _loginBox.getGlobalBounds().height);
    this->_loginBox.move((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.9f);
}

void LoginManager::handleInput(sf::Event &event) {

    switch (event.type) {
        case sf::Event::Closed:
            gGame._gameWindow->close();
            break;
        case sf::Event::KeyReleased:
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    gGame._gameWindow->close();
                    break;
                default:
                    break;
            }
            break;
        case sf::Event::MouseButtonPressed:
            switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    _mousePos = sf::Mouse::getPosition(*gGame._gameWindow);
                    this->handleLoginBoxEvents(_mousePos, 0);
                    break;
                default:
                    break;
                }
            break;
        case sf::Event::MouseMoved:            
            // TODO: Pendiente de revisión
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

                //_loginBox.setFocusedComponent(LoginBox::MainComponents::BotonConectar);
            }
            else {

                _loginBox.setFocusedComponent(LoginBox::MainComponents::MainComponentsQTY);
            }

            break;

        case 1:     // Movimiento de raton
            
            if (_loginBox.getTextBoxUser().getGlobalBounds().contains((sf::Vector2f)pos)) {

                _loginBox.setHoveredComponent(LoginBox::MainComponents::TextBoxUser);
            }
            else if (_loginBox.getTextBoxPassword().getGlobalBounds().contains((sf::Vector2f)pos)) {

                _loginBox.setHoveredComponent(LoginBox::MainComponents::TextBoxPassword);
            }
            else if (_loginBox.getBotonConectar().getGlobalBounds().contains((sf::Vector2f)pos)) {

                _loginBox.setHoveredComponent(LoginBox::MainComponents::BotonConectar);
            }
            else {

                _loginBox.setHoveredComponent(LoginBox::MainComponents::MainComponentsQTY);
            }
            
            break;

        case 2:     // Pulsacion de teclas
            if (_loginBox._focusedTextBox._textBox != nullptr && (c < 128)) {

				switch (c) {

					case 8:		// Tecla BACKSPACE, para borrar el ultimo caracter

                        if (!_loginBox._focusedTextBox._textBox->getString().isEmpty()) {
                            _loginBox._focusedTextBox._textBox->setString(_loginBox._focusedTextBox._textBox->getString().substring(0, _loginBox._focusedTextBox._textBox->getString().getSize() - 1));
                        }

                        if (_loginBox._focusedTextBox._type && !_loginBox._focusedTextBox._pw->getString().isEmpty()) {
                            _loginBox._focusedTextBox._pw->setString(_loginBox._focusedTextBox._pw->getString().substring(0, _loginBox._focusedTextBox._pw->getString().getSize() - 1));
                        }
						break;
					case 27:	// Tecla ESCAPE, lo capturo para que no pinte un simbolo extraño
						break;
                    case 13:	// Tecla RETURN, lo capturo para que no pinte un simbolo extraño
                        break;
                    case 9:
                        if (_loginBox._focusedTextBox._type) {

                            _loginBox.setFocusedComponent(LoginBox::MainComponents::TextBoxUser);
                        }
                        else {

                            _loginBox.setFocusedComponent(LoginBox::MainComponents::TextBoxPassword);
                        }
                        break;
					default:
						if (_loginBox._focusedTextBox._type) {

                            _loginBox._focusedTextBox._pw->setString(_loginBox._focusedTextBox._pw->getString() + c);
							_loginBox._focusedTextBox._textBox->setString(_loginBox._focusedTextBox._textBox->getString() + "*");

						} else {

							_loginBox._focusedTextBox._textBox->setString(_loginBox._focusedTextBox._textBox->getString() + c);
						}
						
						break;
				}
            }

        default:
            break;
    }
}

std::string LoginManager::getUser() {

    return _loginBox.getUser();
}

std::string LoginManager::getPassword() {

    return _loginBox.getPassword();
}

sf::RectangleShape LoginManager::getConnectButton() {

    return _loginBox.getBotonConectar();
}

void LoginManager::onTick() {

    // Vista con los botones del menu
    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(_loginBox);
}

LoginManager::~LoginManager() {
}