#pragma once
#include "SFML/Graphics.hpp"
#include "Game\Unit.h"
#include "Game\TextureManager.h"
#include "GameStatesManager.h"

class GameManager;

extern class Game
{
private:
	GameManager* pGameManager;
	GameStatesManager* pGameStatesManager;
public:
	TextureManager* pTextureManager;
	int iScreenWidth;	///< Tamaño en pixeles del ancho de la pantalla.
	int iScreenHeight;	///< Tamaño en pixeles del alto de la pantalla.
	sf::RenderWindow pGameWindow;	///< Enlace a la pantalla del juego.
	void onTick();		///< Método que se encarga de gestionar el paso del tiempo en el juego.
	Game();
	~Game();
} gGame;

