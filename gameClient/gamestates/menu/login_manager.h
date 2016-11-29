#pragma once

#include "ViewsWrapper.h"
#include "UI/LoginBox.h"

class LoginManager : public ViewsWrapper {
private:
    LoginBox _loginBox;
    sf::Vector2i _mousePos;
    void handleLoginBoxEvents(sf::Vector2i pos, char type, sf::Uint32 c = NULL);

public:
    LoginManager();
    ~LoginManager();

    std::string getUser();
    std::string getPassword();
    sf::RectangleShape getConnectButton();

    void onTick();
    void handleInput(sf::Event &event);
};

