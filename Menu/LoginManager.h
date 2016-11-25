#pragma once

#include <SFML/Graphics.hpp>

#include "ViewsWrapper.h"
#include "UI/LoginBox.h"

class LoginManager : public ViewsWrapper {
private:
    LoginBox _loginBox;
    sf::Vector2i _mousePos;
    void handleLoginBoxEvents(sf::Vector2i pos, char type, char c = NULL);

public:
    LoginManager();
    ~LoginManager();

    void onTick();
    void handleInput(sf::Event &event);
};

