#pragma once

#include <SFML/Graphics.hpp>

class LoginBoxComponent : public sf::Shape, public sf::Text, public sf::Sprite, public sf::Transformable {
private:
    sf::RectangleShape _rectangleShape;
    sf::CircleShape _circleShape;
    sf::ConvexShape _convexShape;
    sf::Text _text;
    sf::Sprite _sprite;

public:

    sf::RectangleShape rectangleShape();
    sf::CircleShape circleShape();
    sf::ConvexShape convexShape();
    sf::Text text();
    sf::Sprite sprite();

    virtual std::size_t getPointCount() const = 0;
    virtual sf::Vector2f getPoint(std::size_t index) const = 0;
    virtual void move(float x, float y);

    LoginBoxComponent();
    ~LoginBoxComponent();
};

