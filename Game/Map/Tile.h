#pragma once

// Referencia externa.
class Grid;

/*
    Clase para los tiles que se usarán de suelo.
*/
class Tile {
    Grid* _grid;
//TODO: Expandir para añadir posibles costes en el pathfinding.
public:
    Tile();
    ~Tile();

    // Grid
    void attatchToGrid(Grid* grid);
    void detatchFromGrid();
};

