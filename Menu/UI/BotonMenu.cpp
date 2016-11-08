#include "BotonMenu.h"
/*
BotonMenu::BotonMenu(std::string texto, sf::Vector2f posicion, sf::Vector2f origen) {

    this->_fuente.loadFromFile("../../media/fonts/big_noodle_titling_oblique.ttf");
    this->_texto = sf::Text(texto, this->_fuente);
    this->_texto.setOrigin(origen);
    this->_texto.setPosition(posicion);
}
*/
BotonMenu::BotonMenu(std::string texto, float posX, float posY, float oriX, float oriY) {

    this->_texto = sf::Text(texto, this->_fuente);
    this->_posicion = sf::Vector2f(posX, posY);
    this->_origen = sf::Vector2f(oriX, oriY);
    this->_texto.setPosition(this->_posicion);
    this->_texto.setOrigin(this->_origen);
}

void BotonMenu::setPosition(float x, float y) {

    this->_texto.setPosition(x, y);
}

void BotonMenu::setOrigin(float x, float y) {

    this->_texto.setOrigin(x, y);
}

std::string BotonMenu::getText() {

    return this->_texto.getString();
}

void BotonMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    states.transform *= getTransform();
    target.draw(this->_texto, states);
}

BotonMenu::~BotonMenu() {
}
