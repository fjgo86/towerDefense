#include <iostream>

#include "../../Game.h"

#include "BotonMenu.h"

BotonMenu::BotonMenu() {
}

BotonMenu::BotonMenu(std::string texto, sf::Vector2f posicion, sf::Vector2f origen) {

    this->crearBoton(texto, posicion, origen);
}

BotonMenu::BotonMenu(std::string texto, float posX, float posY, float oriX, float oriY) {

    this->crearBoton(texto, sf::Vector2f(posX, posY), sf::Vector2f(oriX, oriY));
}

void BotonMenu::crearBoton(std::string texto, sf::Vector2f posicion, sf::Vector2f origen) {

    if (!this->_fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf"))
        std::cout << "No se ha cargado la fuente del boton" << std::endl;

    this->_texto = sf::Text(texto, this->_fuente);
    this->_texto.setFont(this->_fuente);
    this->_texto.setString(texto);
    this->_texto.setOrigin(origen);
    this->_texto.setPosition(posicion);

}

void BotonMenu::setPosition(float x, float y) {

    this->_texto.setPosition(x, y);
}

void BotonMenu::setOrigin(float x, float y) {

    this->_texto.setOrigin(x, y);
}

sf::Vector2f BotonMenu::getPosition() {

    return this->_texto.getPosition();
}

sf::Vector2f BotonMenu::getOrigin() {

    return this->_texto.getOrigin();
}

std::string BotonMenu::getText() {

    return this->_texto.getString();
}

void BotonMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    //states.transform *= getTransform();
    target.draw(_texto, states);

    //std::cout << this->_texto.getString().toAnsiString() << std::endl;

    //sf::Text pedo = sf::Text("pedete", this->_fuente);
    //target.draw(pedo, states);

    //gGame._gameWindow.draw(this->_texto);
    //target.draw(this->_texto);
}

BotonMenu::~BotonMenu() {
}