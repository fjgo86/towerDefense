#pragma once

#include <SFML/Graphics.hpp>

class LoginBox : public sf::Drawable, public sf::Transformable {

private:
    sf::Font _fuente;
    sf::Text _labelUser, _labelPw;
    sf::RectangleShape _labelUserBackground, _labelPwBackground;
    sf::RectangleShape _wrapper, _textBoxUser, _textBoxPw, _buttonConnect;
    //std::vector<sf::RectangleShape> loginBoxRectElements = { _wrapper, _textBoxUser, _textBoxPw };

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

    LoginBox();
    ~LoginBox();
};