#include <iostream>

#include "BotonMenu.h"

#include "../../Game.h"

BotonMenu::BotonMenu() {
}

BotonMenu::BotonMenu(std::string texto, sf::Font &font) {

    this->crearBoton(texto, font, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f));
}

BotonMenu::BotonMenu(std::string texto, sf::Font &font, sf::Vector2f posicion) {

    this->crearBoton(texto, font, posicion, sf::Vector2f(0.f, 0.f));
}

BotonMenu::BotonMenu(std::string texto, sf::Font &font, sf::Vector2f posicion, sf::Vector2f origen) {

    this->crearBoton(texto, font, posicion, origen);
}

BotonMenu::BotonMenu(std::string texto, sf::Font &font, float posX, float posY, float oriX, float oriY) {

    this->crearBoton(texto, font, sf::Vector2f(posX, posY), sf::Vector2f(oriX, oriY));
}

void BotonMenu::crearBoton(std::string texto, sf::Font &font, sf::Vector2f posicion, sf::Vector2f origen) {

    _buttonState = state::normal;

    _texto.setString(texto);
    _texto.setFont(font);
    _texto.setString(texto);
    _texto.setOrigin(origen);
    _texto.setPosition(posicion);
}

void BotonMenu::setPosition(float x, float y) {

    _texto.setPosition(x, y);
}

void BotonMenu::setPosition(sf::Vector2f &pos) {

    _texto.setPosition(pos);
    pos.y -= getBounds().height * 1.5;
}

void BotonMenu::setOrigin(float x, float y) {

    _texto.setOrigin(x, y);
}

void BotonMenu::setText(std::string texto) {

    _texto.setString(texto);
}

void BotonMenu::setState(short estado) {

    _buttonState = estado;
}

void BotonMenu::setType(short tipo) {

    _type = tipo;
}

sf::Vector2f BotonMenu::getPosition() {

    return _texto.getPosition();
}

sf::Vector2f BotonMenu::getOrigin() {

    return _texto.getOrigin();
}

sf::FloatRect BotonMenu::getBounds() {

    return _texto.getGlobalBounds();
}

std::string BotonMenu::getText() {

    return _texto.getString();
}

short BotonMenu::getState() {

    return _buttonState;
}

short BotonMenu::getType() {

    return _type;
}

bool BotonMenu::isVisible() {

    return 1;
}

void BotonMenu::update(sf::Event &e, sf::Window &window) {

    sf::Vector2f _mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    bool mouseHover = this->getBounds().contains(_mousePosition);

    if (e.type == sf::Event::MouseMoved)
        _buttonState = (mouseHover) ? state::hover : state::normal; 

    if ((e.type == sf::Event::MouseButtonPressed) && (e.mouseButton.button == sf::Mouse::Left))
        _buttonState = (mouseHover) ? state::clicked : state::normal;

    if ((e.type == sf::Event::MouseButtonReleased) && (e.mouseButton.button == sf::Mouse::Left))
        _buttonState = (mouseHover) ? state::hover : state::normal;

    switch (_buttonState) {

        case (state::normal): {

            _texto.setFillColor(sf::Color::White);
            break;
        }
        case (state::hover): {

            _texto.setFillColor(sf::Color::Red);
            break;
        }
        case (state::clicked): {

            _texto.setFillColor(sf::Color::Green);
            break;
        }
        default:
            break;
    }
}

void BotonMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(_texto, states);
}

BotonMenu::~BotonMenu() {
}