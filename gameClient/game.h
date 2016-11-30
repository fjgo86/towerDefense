#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "gamestates/game/sprite_manager.h"
#include "gamestates/gamestates_manager.h"
#include "gamestates/game/game_manager.h"
#include "network\clients\client.h"

extern class Game{
public:
    Game();
    ~Game();

    Client *_client;
    GameStatesManager*	_statesManager;
    TextureManager*		_textureManager;
	SpriteManager*		_spriteManager;
    sf::RenderWindow*	_gameWindow;	///< Enlace a la pantalla del juego.
    //sf::Event           _event;

    int _screenWidth;		///< Tama�o en pixeles del ancho de la pantalla.
    int _screenHeight;		///< Tama�o en pixeles del alto de la pantalla.

    void onTick();			///< M�todo que se encarga de gestionar el paso del tiempo en el juego.
    void init();
} gGame;