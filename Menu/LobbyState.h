#pragma once

#include <SFML/Graphics.hpp>

#include "../GameState/GameState.h"
#include "ViewsWrapper.h"
#include "LoginManager.h"
#include "MainMenuManager.h"

class LobbyState : public GameState {

private:
    ViewsWrapper* _vistaActual;
    LoginManager loginView;
    MainMenuManager menuView;

    sf::Shader backgroundShader;
    sf::Sprite background, logo;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1, _backgroundUniform = 0.f;
    float _easingMenu = 0.05f, _xDistanceMenu = 0;

    bool _moveLobby = false;

    /*
    Método para cargar las texturas necesarias
    */
    void loadBackgroundTextures();
    void initLogin();
    void update();

public:
	void moveLobby();
    void onTick();
    void handleInput();

    LobbyState();
    ~LobbyState();
};

