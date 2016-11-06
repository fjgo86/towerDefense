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

    GameStatesManager*	_statesManager;
    TextureManager*		_textureManager;
	SpriteManager*		_spriteManager;
    sf::RenderWindow	_gameWindow;	///< Enlace a la pantalla del juego.

    int _screenWidth;		///< Tama�o en pixeles del ancho de la pantalla.
    int _screenHeight;		///< Tama�o en pixeles del alto de la pantalla.

    void onTick();			///< M�todo que se encarga de gestionar el paso del tiempo en el juego.
} gGame;

