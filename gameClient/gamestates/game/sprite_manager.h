#pragma once
#include <map>

#include "texture_manager.h"
#include <SFML/Graphics/Sprite.hpp>

class SpriteManager : public std::map<std::string, sf::Sprite*> {
private:
	void add(std::string nombre, sf::Sprite* sprite);	///< Añade el Sprite 'sprite' con el nombre 'nombre'.
	TextureManager* _textureManager;					///< Puntero al TextureManager.
public:
	sf::Sprite* loadFromTexture(std::string nombre, sf::Texture &textura);		///< Intenta cargar la Textura 'nombre' y la devuelve como Sprite.
public:
	bool exists(std::string sprite);                    ///< Busca el Sprite 'sprite'.
	sf::Sprite* getRef(std::string sprite);				///< Devuelve el Sprite 'sprite'.
	SpriteManager(TextureManager* textureManager);
	~SpriteManager();
};

