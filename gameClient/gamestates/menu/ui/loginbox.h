#pragma once

#include <SFML/Graphics.hpp>

class LoginBoxFocusedTextBox {
public:
    // Puntero al textbox con el foco
	sf::Text* _textBox;
    // Puntero al password que se va a enviar
    sf::Text* _pw;
	// Tipo de TextBox. 0: Usuario, 1: Password
	bool _type;
    // Puntero al fondo del textbox
    sf::RectangleShape* _rect;

	LoginBoxFocusedTextBox();
	~LoginBoxFocusedTextBox();
};

class LoginBox : public sf::Drawable, public sf::Transformable {

private:

    sf::Font _fuente, _arial;
    sf::Text _labelUser, _labelPw, _botonConectar, _textUser, _textPw, _pw;
    sf::RectangleShape _labelUserBackground, _labelPwBackground;
    sf::RectangleShape _wrapper, _textBoxUser, _textBoxPw, _botonConectarBackground;

    float _focusedOutlineThickness, _unfocusedOutlineThickness;
    sf::Color _hoverOutlineColor, _focusedOutlineColor;
    

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
    void setHoveredComponent(unsigned short int component);

    LoginBoxFocusedTextBox _focusedTextBox;

    sf::Color lightBlue, darkBlue, pink, green;

    sf::RectangleShape* ptrBotonConectar;

    sf::FloatRect getGlobalBounds();
    sf::RectangleShape getBotonConectar();
    sf::RectangleShape getTextBoxUser();
    sf::RectangleShape getTextBoxPassword();
    std::string getUser();
    std::string getPassword();

    LoginBox();
    ~LoginBox();
};