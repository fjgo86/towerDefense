#include "Tile.h"
#include "Grid.h"

Tile::Tile() {
}


Tile::~Tile() {
}

void Tile::attatchToGrid(Grid* grid) {
    _grid = grid;
}

void Tile::detatchFromGrid() {

}