#include "SpriteManager.h"
#include <iostream>

SpriteManager::SpriteManager(TextureManager* textureManager) {
	_textureManager = textureManager;
}


SpriteManager::~SpriteManager() {
}

sf::Sprite* SpriteManager::loadFromTexture(std::string nombre, sf::Texture &textura) {
	if (exists(nombre))		// Si ya est� cargada, se detiene el c�digo.
		return getRef(nombre);

	sf::Sprite sprite(textura);
	add(nombre, &sprite);		// A�ade el Sprite.

	return getRef(nombre);
}

void SpriteManager::add(std::string nombre, sf::Sprite* sprite) {
	(*this)[nombre] = sprite;
}

sf::Sprite* SpriteManager::getRef(std::string sprite) {
	return (*this)[sprite];
}

bool SpriteManager::exists(std::string sprite) {
	return count(sprite) > 0;
}