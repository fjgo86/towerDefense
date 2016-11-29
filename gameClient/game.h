#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "gamestates/game/sprite_manager.h"
#include "gamestates/gamestates_manager.h"
#include "gamestates/game/game_manager.h"

extern class Game{
public:
    Game();
    ~Game();

    GameStatesManager*	_statesManager;
    TextureManager*		_textureManager;
	SpriteManager*		_spriteManager;
    sf::RenderWindow*	_gameWindow;	///< Enlace a la pantalla del juego.
    //sf::Event           _event;

    int _screenWidth;		///< Tamaño en pixeles del ancho de la pantalla.
    int _screenHeight;		///< Tamaño en pixeles del alto de la pantalla.

    void onTick();			///< Método que se encarga de gestionar el paso del tiempo en el juego.
    void init();
} gGame;