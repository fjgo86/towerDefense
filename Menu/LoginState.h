#pragma once

#include <SFML/Graphics.hpp>

#include "../GameState/GameState.h"

class LoginState : public GameState {
private:
    sf::Shader backgroundShader;
    sf::Sprite background, logo;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1, t = 0.f;
    float _easingMenu = 0.05f, _xDistanceMenu = 0;

    sf::View viewBackground, viewLogin;
    sf::CircleShape centerLobby;
    sf::RectangleShape frameLobby;

    void initLogin();
    void update(sf::Event &event);


public:
    LoginState();
    ~LoginState();

    void loadTextures();
    void moveToLobby();

    void onTick();
    void handleInput();
};

