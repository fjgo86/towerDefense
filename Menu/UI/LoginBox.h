#pragma once

#include <SFML/Graphics.hpp>

#include "LoginBoxComponent.h"

class LoginBox : public sf::Drawable, public sf::Transformable {

private:
    /* TODO: implementar esta union en el vector, de modo que acepte los dos tipos

    union vectorTypes {

        sf::Drawable* drawable;
        sf::Transformable* transformable;
    };
    */
    
    sf::Font _fuente;
    sf::Text _labelUser, _labelPw, _botonConectar;
    sf::RectangleShape _labelUserBackground, _labelPwBackground;
    sf::RectangleShape _wrapper, _textBoxUser, _textBoxPw, _botonConectarBackground;

    std::vector<LoginBoxComponent*> _loginBoxComponents;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
    //sf::RectangleShape checkHoverWhat(sf::Vector2f mousePos);

public:

    /*
    Comprobación de eventos
    */
    void update(sf::Event &event);

    LoginBox();
    ~LoginBox();
};