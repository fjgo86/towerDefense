#include "LoginBox.h"
#include "../../Game.h"

LoginBox::LoginBox() {

    _wrapper.setSize(sf::Vector2f(gGame._screenWidth / 2, gGame._screenHeight / 2));
    _wrapper.setOrigin(_wrapper.getGlobalBounds().width / 2, _wrapper.getGlobalBounds().height);
    _wrapper.setPosition(gGame._screenWidth / 2, gGame._screenHeight * 0.9);
    sf::Color _wrapperColor = sf::Color(sf::Color::Cyan.r, sf::Color::Cyan.g, sf::Color::Cyan.b, 80);
    _wrapper.setFillColor(_wrapperColor);

    _textBoxUser.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.7, _wrapper.getGlobalBounds().height * 0.1));
    _textBoxUser.setOrigin(_textBoxUser.getGlobalBounds().width / 2, 0);
    _textBoxUser.setPosition(_wrapper.getPosition().x, _wrapper.getPosition().y - (_wrapper.getGlobalBounds().height * 0.8));

    _textBoxPw.setSize(sf::Vector2f(_wrapper.getGlobalBounds().width * 0.7, _wrapper.getGlobalBounds().height * 0.1));
    _textBoxPw.setOrigin(_textBoxPw.getGlobalBounds().width / 2, 0);
    _textBoxPw.setPosition(_wrapper.getPosition().x, _wrapper.getPosition().y - (_wrapper.getGlobalBounds().height * 0.6));
}

void LoginBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(_wrapper, states);
    target.draw(_textBoxUser, states);
    target.draw(_textBoxPw, states);
}

LoginBox::~LoginBox() {
}
