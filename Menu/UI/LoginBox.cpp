#include "LoginBox.h"
#include "../../Game.h"

LoginBox::LoginBox() {

    _fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");

    // Inicialización de colores
    // rgb(36, 86, 204)
    sf::Color lightBlue = sf::Color(36, 86, 204, 80);
    // rgb(19, 49, 119)
    sf::Color darkBlue = sf::Color(19, 49, 119, 150);
    // rgb(188, 16, 79)
    sf::Color pink = sf::Color(188, 16, 79, 150);

    /*
    Marco exterior (envoltorio de todo)
    */
    _wrapper.setSize(sf::Vector2f((float)gGame._screenWidth / 2, (float)gGame._screenHeight / 2));
	_wrapper.setPosition(0, 0);
    _wrapper.setFillColor(lightBlue);

	_loginBoxComponents.push_back(&_wrapper);

    /*
    Usuario
    */
    _textBoxUser.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.5f, _wrapper.getGlobalBounds().height * 0.1f));
	_textBoxUser.setPosition(_wrapper.getGlobalBounds().width * 0.4f, _wrapper.getGlobalBounds().height * 0.2f);
    _textBoxUser.setFillColor(darkBlue);

    _labelUser.setFont(_fuente);
    _labelUser.setString("Usuario");
    _labelUser.setPosition(_wrapper.getGlobalBounds().width * 0.1f, _wrapper.getGlobalBounds().height * 0.2f);

    sf::FloatRect backgroundRect = _labelUser.getLocalBounds();
    _labelUserBackground.setSize(sf::Vector2f(backgroundRect.width * 1.05f, _textBoxUser.getGlobalBounds().height));
    _labelUserBackground.setFillColor(pink);
	
	// Añadimos los componentes al vector
	_loginBoxComponents.push_back(&_textBoxUser);
	_loginBoxComponents.push_back(&_labelUser);
	_loginBoxComponents.push_back(&_labelUserBackground);

    /*
    Contraseña
    */
    _textBoxPw.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.7f, _wrapper.getGlobalBounds().height * 0.1f));
    _textBoxPw.setOrigin(_textBoxPw.getGlobalBounds().width / 2, 0);
    _textBoxPw.setPosition(_wrapper.getPosition().x, _wrapper.getPosition().y - (_wrapper.getGlobalBounds().height * 0.6f));
    _textBoxPw.setFillColor(darkBlue);

    _labelPw.setFont(_fuente);
    _labelPw.setOrigin(_labelPw.getGlobalBounds().width, _labelPw.getGlobalBounds().height / 2);
    _labelPw.setString("Contraseña");
    _labelPw.setPosition(_textBoxPw.getPosition().x - _textBoxPw.getGlobalBounds().width / 2, _textBoxPw.getPosition().y);

    //backgroundRect = _labelPw.getLocalBounds();
    _labelPwBackground.setSize(sf::Vector2f(backgroundRect.width * 1.05f, _textBoxPw.getGlobalBounds().height));
    _labelPwBackground.setFillColor(pink);

	// Añadimos los componentes al vector
	_loginBoxComponents.push_back(&_textBoxPw);
	_loginBoxComponents.push_back(&_labelPw);
	_loginBoxComponents.push_back(&_labelPwBackground);

	for (std::vector<sf::Transformable*>::iterator i = _loginBoxComponents.begin(); i != _loginBoxComponents.end(); ++i) {
		
		(*i)->move((float)gGame._screenWidth / 4, (float)gGame._screenHeight * 0.4f);
	}
}

void LoginBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(_wrapper, states);

    target.draw(_textBoxUser, _wrapper.getInverseTransform());
    target.draw(_labelUserBackground, _labelUser.getTransform());
    target.draw(_labelUser, states);

    target.draw(_textBoxPw, states);
    target.draw(_labelPwBackground, _labelPw.getTransform());
    target.draw(_labelPw, states);

	/*
	TODO: Implementar este vector que contenga todos los componentes, para poder aplicar transformaciones al vector
	y que se aplique a todos sus componentes a la vez (p.ej: mover el loginBox como si fuera un unico objeto)

	for (std::vector<sf::Drawable>::iterator i = _loginBoxComponents.begin(); i != _loginBoxComponents.end(); ++i) {
		target.draw(*i);
	}
	*/
}

LoginBox::~LoginBox() {
}
