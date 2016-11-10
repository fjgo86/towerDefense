#pragma once

#include <SFML/Graphics.hpp>

class BotonMenu : public sf::Drawable {

/*
Posibles estados del botón
*/
enum state {
    normal = 0,
    hover = 1,
    clicked = 2
};

private:
    sf::Font _fuente;
    sf::Text _texto;
    short _buttonState;

private:
    /*
    Método para construir el botón, se llama desde el constructor de la clase
    */
    void crearBoton(std::string texto, sf::Font &font, sf::Vector2f posicion, sf::Vector2f origen);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

    /*
    Método donde se comprueban los eventos, y se realizan acciones
    */
    void update(sf::Event &e, sf::Window &window);

    // SETTERS
    void setPosition(float x, float y);
    void setOrigin(float x, float y);

    // GETTERS
    sf::Vector2f getPosition();
    sf::Vector2f getOrigin();
    sf::FloatRect getBounds();
    std::string getText();
    short getState();

    // CONSTRUCTORES Y DESTRUCTOR
    BotonMenu();
    BotonMenu(std::string texto, sf::Font &font);
    BotonMenu(std::string texto, sf::Font &font, sf::Vector2f posicion, sf::Vector2f origen);
    BotonMenu(std::string texto, sf::Font &font, float posX, float posY, float oriX, float oriY);
    ~BotonMenu();
};