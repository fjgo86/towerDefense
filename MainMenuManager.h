#pragma once

#include "Game.h"
#include "GameState.h"
#include "GameManager.h"
#include "GameStatesManager.h"

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public GameState {
private:
    sf::Font fuente;
    sf::Text texto;

    GameManager* pGameManager;
    GameStatesManager* pGameStatesManager;

public:
    MainMenuManager();
    ~MainMenuManager();

    void onTick();
    void handleInput();
};

