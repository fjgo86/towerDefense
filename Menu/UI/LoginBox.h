#pragma once

#include <SFML/Graphics.hpp>

class LoginBox : public sf::Drawable, public sf::Transformable {

private:

    sf::Font _fuente;
    sf::Text _labelUser, _labelPw, _botonConectar, _textUser, _textPw;
    sf::RectangleShape _labelUserBackground, _labelPwBackground;
    sf::RectangleShape _wrapper, _textBoxUser, _textBoxPw, _botonConectarBackground;

    
    float _focusedOutlineThickness, _unfocusedOutlineThickness;
    sf::Color _focusedOutlineColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
public:

    enum MainComponents {

        TextBoxUser,
        TextBoxPassword,
        BotonConectar,
        MainComponentsQTY
    };

    void move(float x, float y);
    void setOrigin(float x, float y);
    void setFocusedComponent(unsigned short int component);

    sf::Text* _focusedTextBox;

    sf::FloatRect getGlobalBounds();
    sf::RectangleShape getBotonConectar();
    sf::RectangleShape getTextBoxUser();
    sf::RectangleShape getTextBoxPassword();

    LoginBox();
    ~LoginBox();
};