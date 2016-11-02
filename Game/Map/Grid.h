#pragma once
#include "Tile.h"
#include "../Unit.h"

class Grid {
private:
    Tile* _tile;    ///< Tile de terreno que hay en este Grid.
    Unit* _unit;    ///< Unit que hay en este Grid.
    unsigned int _posX; ///< Posici�n X de este Grid.
    unsigned int _posY; ///< Posici�n Y de este Grid.
public:
    Grid();
    ~Grid();

    void addTile(Tile* tile);   ///< A�ade un Tile al Grid.
    void removeTile(Tile* tile);///< Retira un Tile del Grid.

    void addUnit(Unit* unit);   ///< A�ade una Unit al Grid.
    void removeUnit(Unit* unit);///< Retira una Unit del Grid.

    std::pair<unsigned int, unsigned int> getPosition();    ///< Devuelve un std::pair con la posicion del Grid.

    int getWalkCost();      ///< Devuelve el coste del Grid para el PathFinder.
};

