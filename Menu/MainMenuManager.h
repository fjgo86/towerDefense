#pragma once

#include <SFML/Audio.hpp>

#include "../GameState/GameState.h"
#include "../Game/GameManager.h"
#include "../GameState/GameStatesManager.h"

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public GameState {
private:
    sf::Font fuente;
    sf::Text texto;

    sf::Texture logoTex, musicOn, musicOff;
    sf::Sprite logo;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1;
    sf::Music backgroundMusic;

    /*
    M�todo para actualizar elementos antes de dibujarlos
    */
    void update();

public:
    MainMenuManager();
    ~MainMenuManager();

    void onTick();
    void handleInput();
};

