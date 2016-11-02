#pragma once

// Referencia externa.
class Grid;

/*
    Clase para los tiles que se usar�n de suelo.
*/
class Tile {
    Grid* _grid;
//TODO: Expandir para a�adir posibles costes en el pathfinding.
public:
    Tile();
    ~Tile();

    // Grid
    void attatchToGrid(Grid* grid);
    void detatchFromGrid();
};

