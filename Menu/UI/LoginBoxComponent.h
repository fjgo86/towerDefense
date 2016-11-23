#pragma once

#include <SFML/Graphics.hpp>

class LoginBoxComponent : public sf::Transformable {
public:

    sf::RectangleShape p_rect;

    sf::FloatRect LoginBoxComponent::getGlobalBounds() const;

    LoginBoxComponent();
    ~LoginBoxComponent();
};

