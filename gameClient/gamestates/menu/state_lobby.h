#pragma once

#include <SFML/Graphics.hpp>

#include "../gamestate.h"
#include "ViewsWrapper.h"
#include "login_manager.h"
#include "mainmenu_manager.h"
#include "connection_manager.h"

class LobbyState : public GameState {

private:
    ViewsWrapper* _vistaActual;
    LoginManager loginView;
    ConnectionManager connView;
    MainMenuManager menuView;

    sf::Vector2i _mousePos;

    sf::Shader backgroundShader;
    sf::Sprite background, logo;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1, _backgroundUniform = 0.f;
    float _easingQty = 0.15f, _targetDistance = 0;
    bool _moveLobby = false;

    /*
    Método para cargar las texturas necesarias
    */
    void loadBackgroundTextures();
    void initLogin();
    void update();
    /*
    Método que mueve el Lobby para cambiar entre vistas
    */
    void moveLobby(ViewsWrapper* targetView);
    bool _moveLobbyToRight = true;

public:

    void sendData(std::string u, std::string p);

    ConnectionManager* getConnection();

    void onTick();
    void handleInput();

    LobbyState();
    ~LobbyState();
};