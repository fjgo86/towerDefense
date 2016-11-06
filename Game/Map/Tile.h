#pragma once
#include <SFML/Graphics.hpp>

// Referencia externa.
class Grid;

/*
    Clase para los tiles que se usar�n de suelo.
*/
class Tile {
    Grid* _grid;
	sf::Sprite sfSprite;
//TODO: Expandir para a�adir posibles costes en el pathfinding.
public:
    Tile();
    ~Tile();

    // Grid
    void attatchToGrid(Grid* grid, bool isBorderTile);
    void detatchFromGrid();
    sf::Sprite getSprite();
};

