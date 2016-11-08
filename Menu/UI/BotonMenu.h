#pragma once

#include <SFML/Graphics.hpp>

class BotonMenu : public sf::Drawable, public sf::Transformable {
private:
    sf::Font _fuente;
    sf::Text _texto;
    sf::Vector2f _posicion;
    sf::Vector2f _origen;
    
public:

    virtual void setPosition(float x, float y);
    virtual void setOrigin(float x, float y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::string getText();

    //BotonMenu(std::string texto, sf::Vector2f posicion, sf::Vector2f origen);
    BotonMenu(std::string texto, float posX, float posY, float oriX, float oriY);
    ~BotonMenu();
};

