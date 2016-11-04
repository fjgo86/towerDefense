#pragma once
#include "SFML/Graphics.hpp"
#include "Game/TextureManager.h"
#include "GameState/GameStatesManager.h"
#include "Menu/MainMenuManager.h"

class MainMenuManager;	// Esta trampita me la tienes que explicar. Sin ello el programa peta.

extern class Game{
private:
    MainMenuManager* pMenuManager;
    
public:
    Game();
    ~Game();

    GameStatesManager* pGameStatesManager;
    TextureManager* pTextureManager;
    sf::RenderWindow pGameWindow;	///< Enlace a la pantalla del juego.

    int iScreenWidth;		///< Tama�o en pixeles del ancho de la pantalla.
    int iScreenHeight;		///< Tama�o en pixeles del alto de la pantalla.

    void onTick();			///< M�todo que se encarga de gestionar el paso del tiempo en el juego.
} gGame;

