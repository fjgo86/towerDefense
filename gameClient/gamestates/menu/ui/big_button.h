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

    void setColor(sf::Color color);
    void setOutlineThickness(float thickness);

    sf::FloatRect getGlobalBounds();

    BigButton(std::string texturePath, std::string texto);
    ~BigButton();
};