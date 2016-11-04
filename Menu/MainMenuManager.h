#pragma once

#include "../Game.h"
#include "../GameState/GameState.h"
#include "../Game/GameManager.h"
#include "../GameState/GameStatesManager.h"
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

