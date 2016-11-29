#pragma once

#include <SFML/Graphics.hpp>

class ViewsWrapper : public sf::View {
public:
    enum Views {
        LoginView,
        ConnectionView,
        MenuView,
        ViewsQTY
    };

    unsigned short viewId;

    virtual void onTick() = 0;
    virtual void handleInput(sf::Event &event) = 0;

    ViewsWrapper();
    ~ViewsWrapper();
};

