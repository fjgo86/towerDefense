#pragma once
#include "SFML/Graphics.hpp"
#include "Game\Unit.h"
#include "Game\TextureManager.h"

class GameManager;

extern class Game
{
private:
	GameManager* gameManager;
public:
	TextureManager* textureManager;
	int screenWidth;	///< Tama�o en pixeles del ancho de la pantalla.
	int screenHeight;	///< Tama�o en pixeles del alto de la pantalla.
	sf::RenderWindow window;	///< Enlace a la pantalla del juego.
	void onTick();		///< M�todo que se encarga de gestionar el paso del tiempo en el juego.
	Game();
	~Game();
} gGame;

