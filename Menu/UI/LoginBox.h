#pragma once

#include <SFML/Graphics.hpp>

#include "LoginBoxComponent.h"

class LoginBox : public sf::Drawable, public sf::Transformable {

private:

    sf::Font _fuente;
    sf::Text _labelUser, _labelPw, _botonConectar;
    sf::RectangleShape _labelUserBackground, _labelPwBackground;
    sf::RectangleShape _wrapper, _textBoxUser, _textBoxPw, _botonConectarBackground;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
    sf::RectangleShape checkHoverWhat(sf::Vector2f mousePos);

    void move(float x, float y);
public:

    /*
    Comprobación de eventos
    */
    void update(sf::Event &event);

    LoginBox();
    ~LoginBox();
};