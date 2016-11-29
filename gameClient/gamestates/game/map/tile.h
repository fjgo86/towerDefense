#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

// Referencia externa.
class Grid;

/*
    Clase para los tiles que se usarán de suelo.
*/
class Tile {
    Grid* _grid;
	sf::Sprite sfSprite;
	sf::Texture* sfTexture;
//TODO: Expandir para añadir posibles costes en el pathfinding.
public:
    Tile();
    ~Tile();

    // Grid
    void attatchToGrid(Grid* grid);
    void detatchFromGrid();
    sf::Sprite getSprite();
};

