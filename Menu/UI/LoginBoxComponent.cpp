#include "LoginBoxComponent.h"

LoginBoxComponent::LoginBoxComponent() {
}

sf::RectangleShape LoginBoxComponent::rectangleShape() {

    return _rectangleShape;
}

sf::CircleShape LoginBoxComponent::circleShape() {

    return _circleShape;
}

sf::ConvexShape LoginBoxComponent::convexShape() {

    return _convexShape;
}

sf::Text LoginBoxComponent::text() {

    return _text;
}

sf::Sprite LoginBoxComponent::sprite() {

    return _sprite;
}

void LoginBoxComponent::move(float x, float y) {

    (*this).move(x, y);
}

LoginBoxComponent::~LoginBoxComponent() {
}
