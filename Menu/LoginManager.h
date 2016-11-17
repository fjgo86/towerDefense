#pragma once

#include <SFML/Graphics.hpp>

#include "UI/LoginBox.h"

class LoginManager : public sf::View {
private:
    LoginBox _loginBox;

public:
    LoginManager();
    ~LoginManager();

    void onTick();
    void handleInput(sf::Event &event);
};

