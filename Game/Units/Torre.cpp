#include "Torre.h"
#include "Enemigo.h"
#include <iostream>

Torre::Torre() {
    this->initRangeCircle();
}

Torre::~Torre() {
}

bool Torre::onTick(const float elapsed) {
    if (checkMouseOver())
        gGame._gameWindow.draw(this->rangeCircle);
    draw(elapsed);
    return true;
}

bool Torre::checkMouseOver() {
    sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(gGame._gameWindow).x, (float)sf::Mouse::getPosition(gGame._gameWindow).y);
    return getFloatRect().contains(mousePos) ? true : false;
}

void Torre::initRangeCircle() {
    this->rangeCircle.setPointCount(50);
    this->rangeCircle.setRadius(this->range);
    this->rangeCircle.setFillColor(sf::Color(50, 192, 240, 75));
    this->rangeCircle.setOutlineColor(sf::Color(50, 192, 240, 150));
    this->rangeCircle.setOutlineThickness(1);
    this->rangeCircle.setPosition(sf::Vector2f((float)sf::Mouse::getPosition(gGame._gameWindow).x, (float)sf::Mouse::getPosition(gGame._gameWindow).y));
    this->rangeCircle.setOrigin(this->range, this->range);
}

int Torre::getWalkCost() {
    return 9;
}

int Torre::getWalkCostFor(Enemigo * enemigo) {
    if (enemigo->canFly() && range <= 16.0f) // Si el enemigo vuela y la torre no tiene ataques a distancia, la ignora.
        return 5;   // Recibe el máximo coste, dándole al enemigo la posibilidad de pasar por encima pero evadiéndola de ser posible.
    return 9;       // Si no, la torre es impasable.
}