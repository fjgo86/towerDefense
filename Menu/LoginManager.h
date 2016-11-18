#pragma once

#include <SFML/Graphics.hpp>

#include "ViewsWrapper.h"
#include "UI/LoginBox.h"

class LoginManager : public ViewsWrapper {
private:
    LoginBox _loginBox;

public:
    LoginManager();
    ~LoginManager();

    void onTick();
    void handleInput(sf::Event &event);
};

