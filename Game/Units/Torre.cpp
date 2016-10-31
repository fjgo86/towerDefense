#include "Torre.h"
#include <iostream>

Torre::Torre()
{
	this->initRangeCircle();
}

Torre::~Torre()
{
}

bool Torre::onTick(const float elapsed)
{
	//std::cout << "Torre::onTick" << std::endl;
	if (checkMouseOver()) gGame.pGameWindow.draw(this->rangeCircle);
	draw(elapsed);

	return true;
}

bool Torre::checkMouseOver()
{
	sf::FloatRect floatRect = getFloatRect();
	sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(gGame.pGameWindow).x, (float)sf::Mouse::getPosition(gGame.pGameWindow).y);

	return floatRect.contains(mousePos) ? true : false;
}

void Torre::initRangeCircle()
{
	this->rangeCircle.setPointCount(50);
	this->rangeCircle.setRadius(150);
	this->rangeCircle.setFillColor(sf::Color(50, 192, 240, 75));
	this->rangeCircle.setOutlineColor(sf::Color(50, 192, 240, 150));
	this->rangeCircle.setOutlineThickness(1);
	this->rangeCircle.setPosition(getPosition());
	this->rangeCircle.setOrigin(getOrigin());
}