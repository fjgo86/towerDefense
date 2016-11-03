#pragma once

#include "Game.h"
#include "GameState.h"
#include "GameManager.h"
#include "GameStatesManager.h"
#include <SFML/Audio.hpp>

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public GameState {
private:
    sf::Font fuente;
    sf::Text texto;

    sf::Texture logoTex;
    sf::Sprite logo;
    int alphaLogo = 0;
    float scaleLogo = 1;
    sf::Music backgroundMusic;

    GameManager* pGameManager;

    void update();  ///< M�todo para actualizar elementos antes de dibujarlos

public:
    MainMenuManager();
    ~MainMenuManager();

    void onTick();
    void handleInput();
};

