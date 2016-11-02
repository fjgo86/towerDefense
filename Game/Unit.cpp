#include "Unit.h"
#include <iostream>

Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::draw(const float elapsed)
{
	animatedSprite.draw();
	animatedSprite.update(elapsed);
}

const char* Unit::getNombre()
{
	return _nombre;
}

void Unit::setNombre(const char * nombreNuevo)
{
	std::cout << "setNombre(" << nombreNuevo << ")" << std::endl;
	_nombre = nombreNuevo;
}

void Unit::setRutaImagen(const char * ruta)
{
	_rutaImagen = ruta;
	if ((_rutaImagen == NULL))
	{
		std::cout << "Ruta de imagen inexistente para " << getNombre() << "." << std::endl;
		return;
	}
	animatedSprite = AnimatedSprite(getNombre(), _rutaImagen);
}

void Unit::setPosition(float x, float y)
{
	animatedSprite.setPosition((float)x, (float)y);
}

void Unit::setOrigin(bool centered)
{
	animatedSprite.setOrigin((bool)centered);
}

void Unit::setOrigin(float x, float y)
{
	animatedSprite.setOrigin((float)x, (float)y);
}

sf::FloatRect Unit::getFloatRect()
{
	return animatedSprite.getFloatRect();
}

sf::Vector2f Unit::getPosition()
{
	return animatedSprite.getPosition();
}

sf::Vector2f Unit::getOrigin()
{
	return animatedSprite.getOrigin();
}

int Unit::getDireccion()
{
	return animatedSprite.getDireccion();
}

void Unit::attatchToGrid(Grid* grid) {
    _grid = grid;
}

void Unit::detatchFromGrid() {

}