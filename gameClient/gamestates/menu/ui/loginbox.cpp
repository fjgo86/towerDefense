#include <iostream>

#include "loginbox.h"
#include <logger/logger.h>
#include "../../../Game.h"

LoginBoxFocusedTextBox::LoginBoxFocusedTextBox() {
}

LoginBoxFocusedTextBox::~LoginBoxFocusedTextBox(){
}

LoginBox::LoginBox() {

    _fuente = gGame._globalFont;
    _arial.loadFromFile("../gameClient/media/fonts/PT_Sans-Narrow-Web-Regular.ttf");

    // Inicialización de valores por defecto
    _focusedOutlineThickness = 2.f;
    _unfocusedOutlineThickness = 0.f;
    _focusedOutlineColor = sf::Color(134, 179, 249, 200);

    // Inicializando punteros a null para evitar "wild pointers"
    _focusedTextBox._textBox = nullptr;
    _focusedTextBox._rect = nullptr;

    // Inicialización de colores
    // rgb(36, 86, 204)
    lightBlue = sf::Color(36, 86, 204, 80);
    // rgb(19, 49, 119)
    darkBlue = sf::Color(19, 49, 119, 150);
    // rgb(188, 16, 79)
    pink = sf::Color(188, 16, 79, 150);
    // rgb(5, 178, 25)
    green = sf::Color(5, 178, 25, 150);

    /*
    Marco exterior (envoltorio de todo)
    */
    _wrapper.setSize(sf::Vector2f((float)gGame._screenWidth / 2, (float)gGame._screenHeight / 2));
	_wrapper.setPosition(0, 0);
    _wrapper.setFillColor(lightBlue);

    /*
    Usuario
    */
    _textBoxUser.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.5f, _wrapper.getGlobalBounds().height * 0.1f));
	_textBoxUser.setPosition(_wrapper.getGlobalBounds().width * 0.4f, _wrapper.getGlobalBounds().height * 0.2f);
    _textBoxUser.setFillColor(darkBlue);

    _labelUser.setFont(_fuente);
    _labelUser.setString("Usuario");
    _labelUser.setPosition(_wrapper.getGlobalBounds().width * 0.125f, _wrapper.getGlobalBounds().height * 0.2f);

    _labelUserBackground.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.25f, _labelUser.getGlobalBounds().height * 1.8f));
    _labelUserBackground.setPosition(_labelUser.getPosition().x * 0.8f, _labelUser.getPosition().y);
    _labelUserBackground.setFillColor(pink);

    // Texto de usuario DENTRO del textbox
    _textUser.setFont(_arial);
    _textUser.setPosition(_textBoxUser.getPosition().x + (_textBoxUser.getGlobalBounds().width * 0.05f), _textBoxUser.getPosition().y);

    /*
    Contraseña
    */
    _textBoxPw.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.5f, _wrapper.getGlobalBounds().height * 0.1f));
    _textBoxPw.setPosition(_wrapper.getGlobalBounds().width * 0.4f, (_wrapper.getGlobalBounds().height * 0.2f + _textBoxPw.getGlobalBounds().height * 1.5f));
    _textBoxPw.setFillColor(darkBlue);

    _labelPw.setFont(_fuente);
    _labelPw.setString("Contraseña");
    _labelPw.setPosition(_wrapper.getGlobalBounds().width * 0.125f, (_wrapper.getGlobalBounds().height * 0.2f + _labelPw.getGlobalBounds().height * 2));

    _labelPwBackground.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.25f, _labelPw.getGlobalBounds().height * 1.4f));
    _labelPwBackground.setPosition(_labelPw.getPosition().x * 0.8f , _labelPw.getPosition().y);
    _labelPwBackground.setFillColor(pink);

    // Texto de contraseña DENTRO del textbox
    _textPw.setFont(_arial);
    _textPw.setPosition(_textBoxPw.getPosition().x + (_textBoxPw.getGlobalBounds().width * 0.05f), _textBoxPw.getPosition().y);

    /*
    Boton "Conectar"
    */
    _botonConectar.setFont(_fuente);
    _botonConectar.setString("Conectar");
    _botonConectar.setOrigin(_botonConectar.getGlobalBounds().width / 2, _botonConectar.getGlobalBounds().height / 2);
    _botonConectar.setPosition(((_wrapper.getGlobalBounds().width / 2) - (_botonConectar.getGlobalBounds().width / 2)), _wrapper.getGlobalBounds().height * 0.7f);

    _botonConectarBackground.setSize(sf::Vector2f(_botonConectar.getGlobalBounds().width * 1.5f, _botonConectar.getGlobalBounds().height * 2.f));
    _botonConectarBackground.setOrigin(_botonConectarBackground.getGlobalBounds().width / 2, _botonConectarBackground.getGlobalBounds().height / 2);
    _botonConectarBackground.setPosition((_botonConectar.getPosition().x) - (_botonConectar.getGlobalBounds().width / 4), (_botonConectar.getPosition().y) - (_botonConectar.getGlobalBounds().height / 4));
    _botonConectarBackground.setFillColor(green);
}

void LoginBox::move(float x, float y) {

    _wrapper.move(x, y);
    
    _textBoxUser.move(x, y);
    _labelUser.move(x, y);
    _labelUserBackground.move(x, y);
    _textUser.move(x, y);

    _textBoxPw.move(x, y);
    _labelPw.move(x, y);
    _labelPwBackground.move(x, y);
    _textPw.move(x, y);
    
    _botonConectar.move(x, y);
    _botonConectarBackground.move(x, y);
}

void LoginBox::setOrigin(float x, float y) {

    _wrapper.setOrigin(x, y);

    _textBoxUser.setOrigin(x, y);
    _textUser.setOrigin(x, y);
    _labelUser.setOrigin(x, y);
    _labelUserBackground.setOrigin(x, y);

    _textBoxPw.setOrigin(x, y);
    _labelPw.setOrigin(x, y);
    _labelPwBackground.setOrigin(x, y);
    _textPw.setOrigin(x, y);

    _botonConectar.setOrigin(x, y);
    _botonConectarBackground.setOrigin(x, y);
}

void LoginBox::setFocusedComponent(unsigned short int component) {

    _textBoxUser.setOutlineColor(_focusedOutlineColor);
    _textBoxUser.setOutlineThickness(_unfocusedOutlineThickness);

    _textBoxPw.setOutlineColor(_focusedOutlineColor);
    _textBoxPw.setOutlineThickness(_unfocusedOutlineThickness);

    _botonConectarBackground.setOutlineColor(_focusedOutlineColor);
    _botonConectarBackground.setOutlineThickness(_unfocusedOutlineThickness);

    switch (component) {
        case MainComponents::TextBoxUser:
            _focusedTextBox._textBox = &_textUser;
            _focusedTextBox._rect = &_textBoxUser;
			_focusedTextBox._type = 0;
            _textBoxUser.setOutlineThickness(_focusedOutlineThickness);
            break;

        case MainComponents::TextBoxPassword:
            _focusedTextBox._textBox = &_textPw;
            _focusedTextBox._rect = &_textBoxPw;
            _focusedTextBox._pw = &_pw;
			_focusedTextBox._type = 1;
            _textBoxPw.setOutlineThickness(_focusedOutlineThickness);
            break;

        case MainComponents::BotonConectar:
            _focusedTextBox._rect = &_botonConectarBackground;
            _botonConectarBackground.setOutlineThickness(_focusedOutlineThickness);
            break;

        case MainComponents::MainComponentsQTY:
            _focusedTextBox._rect = nullptr;
            _focusedTextBox._textBox = nullptr;
            break;

        default:
            break;
    }
}

/*
TODO: Esta función queda pendiente de revisión, porque no funciona muy bien
*/
void LoginBox::setHoveredComponent(unsigned short int component) {
    /*
    if (_focusedTextBox._rect != nullptr) {

    _textBoxUser.setOutlineColor(_hoverOutlineColor);
    _textBoxUser.setOutlineThickness(_unfocusedOutlineThickness);

    _textBoxPw.setOutlineColor(_hoverOutlineColor);
    _textBoxPw.setOutlineThickness(_unfocusedOutlineThickness);

    _botonConectarBackground.setOutlineColor(_hoverOutlineColor);
    _botonConectarBackground.setOutlineThickness(_unfocusedOutlineThickness);
    }
    */
    switch (component) {
        /*
        case MainComponents::TextBoxUser:
        _textBoxUser.setOutlineThickness(_focusedOutlineThickness);
        break;

        case MainComponents::TextBoxPassword:
        _textBoxPw.setOutlineThickness(_focusedOutlineThickness);
        break;
        */
        case MainComponents::BotonConectar:
            _LOG(Log::LOGLVL_DEBUG, "hover BotonConectar\n");
            _botonConectarBackground.setOutlineThickness(_focusedOutlineThickness);
            break;

        case MainComponents::MainComponentsQTY:
            //_textBoxUser.setOutlineColor(_hoverOutlineColor);
            //_textBoxPw.setOutlineColor(_hoverOutlineColor);
            //_botonConectarBackground.setOutlineColor(_hoverOutlineColor);
            break;

        default:
            //_focusedTextBox._rect->setOutlineColor(_hoverOutlineColor);
            break;
    }
}

std::string LoginBox::getUser() {

    return _textUser.getString();
}

std::string LoginBox::getPassword() {

    return _pw.getString();
}

sf::FloatRect LoginBox::getGlobalBounds() {

    return _wrapper.getGlobalBounds();
}

sf::RectangleShape LoginBox::getBotonConectar() {

    return _botonConectarBackground;
}

sf::RectangleShape LoginBox::getTextBoxUser() {

    return _textBoxUser;
}

sf::RectangleShape LoginBox::getTextBoxPassword() {

    return _textBoxPw;
}

void LoginBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    
    target.draw(_wrapper, states);

    target.draw(_textBoxUser, states);
    target.draw(_labelUserBackground, states);
    target.draw(_labelUser, states);
    target.draw(_textUser, states);

    target.draw(_textBoxPw, states);
    target.draw(_labelPwBackground, states);
    target.draw(_labelPw, states);
    target.draw(_textPw, states);
    
    target.draw(_botonConectarBackground, states);
    target.draw(_botonConectar, states);

	/*
	// TODO: Implementar este vector que contenga todos los componentes, para poder aplicar transformaciones al vector
	// y que se aplique a todos sus componentes a la vez (p.ej: mover el loginBox como si fuera un unico objeto)

	for (std::vector<sf::Transformable*>::iterator i = _loginBoxComponents.begin(); i != _loginBoxComponents.end(); ++i) {
		target.draw(*i);
	}
	*/
}

LoginBox::~LoginBox() {
}
