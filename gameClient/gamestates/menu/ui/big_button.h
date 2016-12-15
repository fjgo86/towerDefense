#pragma once

#include <SFML/Graphics.hpp>

class BigButton : public sf::Drawable, public sf::Transformable {
private:
    sf::RectangleShape buttonBackground;
    sf::Font buttonFont;
    sf::Text buttonText;
    sf::Texture buttonTexture;
    sf::Sprite buttonSprite;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    BigButton(std::string texturePath, std::string texto);
    ~BigButton();
};