#include "BotonMenu.h"

BotonMenu::BotonMenu(std::string texto, sf::Vector2f posicion, sf::Vector2f origen) {

    this->_fuente.loadFromFile("../../media/fonts/big_noodle_titling_oblique.ttf");
    this->_texto = sf::Text(texto, this->_fuente);
    this->_texto.setOrigin(origen);
    this->_texto.setPosition(posicion);
}

BotonMenu::BotonMenu(std::string texto, float posX, float posY, float oriX, float oriY) {

    this->_posicion = sf::Vector2f(posX, posY);
    this->_origen = sf::Vector2f(oriX, oriY);
}

BotonMenu* BotonMenu::getBoton() {

    return this;
}

BotonMenu::~BotonMenu() {
}
