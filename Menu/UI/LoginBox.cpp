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
    _wrapper.setSize(sf::Vector2f(gGame._screenWidth / 2, gGame._screenHeight / 2));
    _wrapper.setOrigin(_wrapper.getGlobalBounds().width / 2, _wrapper.getGlobalBounds().height);
    _wrapper.setPosition(gGame._screenWidth / 2, gGame._screenHeight * 0.9);
    _wrapper.setFillColor(lightBlue);

    /*
    Usuario
    */
    _textBoxUser.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.7, _wrapper.getGlobalBounds().height * 0.1));
    _textBoxUser.setOrigin(_textBoxUser.getGlobalBounds().width / 2, 0);
    _textBoxUser.setPosition(_wrapper.getPosition().x, _wrapper.getPosition().y - (_wrapper.getGlobalBounds().height * 0.8));
    _textBoxUser.setFillColor(darkBlue);

    _labelUser.setFont(_fuente);
    _labelUser.setOrigin(_labelUser.getGlobalBounds().width, _labelUser.getGlobalBounds().height / 2);
    _labelUser.setString("Usuario");
    _labelUser.setPosition(_textBoxUser.getPosition().x - _textBoxUser.getGlobalBounds().width / 2, _textBoxUser.getPosition().y);

    sf::FloatRect backgroundRect = _labelUser.getLocalBounds();
    _labelUserBackground.setSize(sf::Vector2f(backgroundRect.width * 1.05, _textBoxUser.getGlobalBounds().height));
    _labelUserBackground.setFillColor(pink);

    /*
    Contraseña
    */
    _textBoxPw.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.7, _wrapper.getGlobalBounds().height * 0.1));
    _textBoxPw.setOrigin(_textBoxPw.getGlobalBounds().width / 2, 0);
    _textBoxPw.setPosition(_wrapper.getPosition().x, _wrapper.getPosition().y - (_wrapper.getGlobalBounds().height * 0.6));
    _textBoxPw.setFillColor(darkBlue);

    _labelPw.setFont(_fuente);
    _labelPw.setOrigin(_labelPw.getGlobalBounds().width, _labelPw.getGlobalBounds().height / 2);
    _labelPw.setString("Contraseña");
    _labelPw.setPosition(_textBoxPw.getPosition().x - _textBoxPw.getGlobalBounds().width / 2, _textBoxPw.getPosition().y);

    backgroundRect = _labelPw.getLocalBounds();
    _labelPwBackground.setSize(sf::Vector2f(backgroundRect.width * 1.05, _textBoxPw.getGlobalBounds().height));
    _labelPwBackground.setFillColor(pink);
}

void LoginBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(_wrapper, states);

    target.draw(_textBoxUser, states);
    target.draw(_labelUserBackground, _labelUser.getTransform());
    target.draw(_labelUser, states);

    target.draw(_textBoxPw, states);
    target.draw(_labelPwBackground, _labelPw.getTransform());
    target.draw(_labelPw, states);
}

LoginBox::~LoginBox() {
}
