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
    // rgb(5, 178, 25)
    sf::Color green = sf::Color(5, 178, 25, 150);

    /*
    Marco exterior (envoltorio de todo)
    */
    _wrapper.setSize(sf::Vector2f((float)gGame._screenWidth / 2, (float)gGame._screenHeight / 2));
	_wrapper.setPosition(0, 0);
    _wrapper.setFillColor(lightBlue);

	_loginBoxComponents.push_back((LoginBoxComponent*)&_wrapper);

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

	// Añadimos los componentes al vector
	_loginBoxComponents.push_back((LoginBoxComponent*)&_textBoxUser);
	_loginBoxComponents.push_back((LoginBoxComponent*)&_labelUser);
	_loginBoxComponents.push_back((LoginBoxComponent*)&_labelUserBackground);

    /*
    Contraseña
    */
    _textBoxPw.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.5f, _wrapper.getGlobalBounds().height * 0.1f));
    _textBoxPw.setOrigin(0, _textBoxPw.getGlobalBounds().height / 2);
    _textBoxPw.setPosition(_wrapper.getGlobalBounds().width * 0.4f, (_wrapper.getGlobalBounds().height * 0.2f + _textBoxPw.getGlobalBounds().height * 2));
    _textBoxPw.setFillColor(darkBlue);

    _labelPw.setFont(_fuente);
    _labelPw.setString("Contraseña");
    _labelPw.setPosition(_wrapper.getGlobalBounds().width * 0.125f, (_wrapper.getGlobalBounds().height * 0.2f + _labelPw.getGlobalBounds().height * 2));

    _labelPwBackground.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.25f, _labelPw.getGlobalBounds().height * 1.4f));
    _labelPwBackground.setPosition(_labelPw.getPosition().x * 0.8f , _labelPw.getPosition().y);
    _labelPwBackground.setFillColor(pink);

	// Añadimos los componentes al vector
	_loginBoxComponents.push_back((LoginBoxComponent*)&_textBoxPw);
	_loginBoxComponents.push_back((LoginBoxComponent*)&_labelPw);
	_loginBoxComponents.push_back((LoginBoxComponent*)&_labelPwBackground);

    /*
    Boton "Conectar"
    */

    _botonConectar.setFont(_fuente);
    _botonConectar.setString("Conectar");
    _botonConectar.setOrigin(_botonConectar.getGlobalBounds().width / 2, _botonConectar.getGlobalBounds().height / 2);
    _botonConectar.setPosition(_wrapper.getGlobalBounds().width / 2, _wrapper.getGlobalBounds().height *0.7f);

    _botonConectarBackground.setSize(sf::Vector2f(_botonConectar.getGlobalBounds().width * 1.5f, _botonConectar.getGlobalBounds().height * 2.f));
    _botonConectarBackground.setOrigin(_botonConectarBackground.getGlobalBounds().width / 2, _botonConectarBackground.getGlobalBounds().height / 2);
    _botonConectarBackground.setPosition(_botonConectar.getPosition().x, _botonConectar.getPosition().y);
    _botonConectarBackground.setFillColor(green);

    // Añadimos el boton al vector
    _loginBoxComponents.push_back((LoginBoxComponent*)&_botonConectar);
    _loginBoxComponents.push_back((LoginBoxComponent*)&_botonConectarBackground);

    /*
    Movemos el conjunto al centro de la pantalla
    */

	for (std::vector<LoginBoxComponent*>::iterator i = _loginBoxComponents.begin(); i != _loginBoxComponents.end(); ++i) {
		
		//(*i)->move((float)gGame._screenWidth / 4, (float)gGame._screenHeight * 0.4f);
        
	}
}

void LoginBox::update(sf::Event &event) {

    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(gGame._gameWindow));
    //sf::RectangleShape mouseHover = checkHoverWhat(mousePosition);
}
/*
sf::RectangleShape LoginBox::checkHoverWhat(sf::Vector2f m_mousePosition) {
    
    for (std::vector<sf::Transformable*>::iterator i = _loginBoxComponents.begin(); i != _loginBoxComponents.end(); ++i) {

        (*i)->
    }
    
}
*/

void LoginBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    
    target.draw(_wrapper, states);

    target.draw(_textBoxUser, states);
    target.draw(_labelUserBackground, states);
    target.draw(_labelUser, states);

    target.draw(_textBoxPw, states);
    target.draw(_labelPwBackground, states);
    target.draw(_labelPw, states);
    
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
