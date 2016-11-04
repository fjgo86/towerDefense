
#include <iostream>

#include "Grid.h"

#include "../../Game.h"
#include "Map.h"

Grid::Grid(unsigned int x, unsigned int y, bool isBorderGrid) {
    _posX = x;
    _posY = y;
    _unit = nullptr;
    _tile = new Tile();
    _tile->attatchToGrid(this, isBorderGrid);
}

Grid::~Grid() {
    delete _tile;
}

void Grid::addTile(Tile * tile) {
    if (_tile != nullptr) {
        std::cout << "A�adiendo tile a Grid con tile previo ("<< _posX << ", "<< _posY << ")" << std::endl;
        return;
    }
    _tile = tile;
}

void Grid::removeTile(Tile * tile) {
    _tile = nullptr;
    tile->detatchFromGrid();
}

void Grid::addUnit(Unit * unit) {
    if (_unit != nullptr) {
        std::cout << "A�adiendo Unit a Grid con Unit previa (" << _posX << ", " << _posY << ")" << std::endl;
        return;
    }
    _unit = unit;
    // TODO: Cambiar el _coste de Grids contiguos al emplazar una Torre, actualizar tambi�n el removeUnit acorde a los cambios.
}

void Grid::removeUnit(Unit * unit) {
    _unit = nullptr;
    unit->detatchFromGrid();
}

std::pair<unsigned int, unsigned int> Grid::getPosition() {
    return std::pair<unsigned int, unsigned int>(_posX, _posY);
}

int Grid::getWalkCost() {
    if (_unit != nullptr) {
        return _unit->getWalkCost();
    }
    else if (_tile != nullptr) {
        return 0;
    }
 
   return -1;
}

void Grid::onTick() {
    if (_tile != nullptr)
        gGame._gameWindow.draw(_tile->getSprite());
}
