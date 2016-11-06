#pragma once
#include <SFML/Graphics.hpp>
#include "Game/SpriteManager.h"
#include "GameState/GameStatesManager.h"
#include "Game/GameManager.h"

class MainMenuManager;

extern class Game{
public:
    Game();
    ~Game();

	MainMenuManager* _menu;
	GameManager* _game;

    GameStatesManager*	_statesManager;
    TextureManager*		_textureManager;
	SpriteManager*		_spriteManager;
    sf::RenderWindow	_gameWindow;	///< Enlace a la pantalla del juego.

    int _screenWidth;		///< Tamaño en pixeles del ancho de la pantalla.
    int _screenHeight;		///< Tamaño en pixeles del alto de la pantalla.

    void onTick();			///< Método que se encarga de gestionar el paso del tiempo en el juego.
} gGame;

