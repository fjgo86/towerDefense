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

    sf::Vector2i _mousePos;

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
    /*
    Método que mueve "echa" al login y "mete" al menú
    */
    void moveLobby(); 

public:
	
    void sendData(std::string u, std::string p);

    void onTick();
    void handleInput();

    LobbyState();
    ~LobbyState();
};

