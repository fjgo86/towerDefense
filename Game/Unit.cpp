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

void Unit::setNombre(const char * nombreNuevo)
{
	std::cout << "setNombre(" << nombreNuevo << ")" << std::endl;
	nombre = nombreNuevo;
}

void Unit::setRutaImagen(const char * ruta)
{
	rutaImagen = ruta;
	if ((rutaImagen == NULL))
	{
		std::cout << "Ruta de imagen inexistente para " << getNombre() << "." << std::endl;
		return;
	}
	animatedSprite = AnimatedSprite(getNombre(), rutaImagen);
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

void Unit::setDireccion(int dir)
{
	animatedSprite.setDireccion(dir);
}

const char * Unit::getNombre()
{
	return nombre;
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