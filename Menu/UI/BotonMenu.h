#pragma once

#include <SFML/Graphics.hpp>

class BotonMenu : public sf::Drawable, public sf::Transformable {
private:
    sf::Font _fuente;
    sf::Text _texto;

private:
    void crearBoton(std::string texto, sf::Vector2f posicion, sf::Vector2f origen);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

    void setPosition(float x, float y);
    void setOrigin(float x, float y);
    
    sf::Vector2f getPosition();
    sf::Vector2f getOrigin();
    std::string getText();

    BotonMenu();
    BotonMenu(std::string texto, sf::Vector2f posicion, sf::Vector2f origen);
    BotonMenu(std::string texto, float posX, float posY, float oriX, float oriY);
    ~BotonMenu();
};

