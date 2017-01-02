#pragma once

#include <SFML/Graphics.hpp>

class BigButton : public sf::RectangleShape {
private:
    sf::Font buttonFont;
    sf::Text buttonText;
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:

    BigButton(std::string texturePath, std::string texto);
    ~BigButton();
};