#include <iostream>

#include "grid.h"
#include "map.h"

#include "../../../game.h"

bool Grid::isBorderGrid() {
	return _isBorderGrid;
}

Grid::Grid(unsigned int x, unsigned int y, bool isBorderGrid) {
    _posX = x;
    _posY = y;
    _unit = nullptr;
	_isBorderGrid = isBorderGrid;
    _tile = new Tile();
    _tile->attatchToGrid(this);
}

Grid::~Grid() {
    delete _tile;
}

void Grid::addTile(Tile * tile) {
    if (_tile != nullptr) {
        std::cout << "Añadiendo tile a Grid con tile previo ("<< _posX << ", "<< _posY << ")" << std::endl;
        return;
    }
    _tile = tile;
}

void Grid::removeTile(Tile * tile) {
    _tile = nullptr;
    tile->detatchFromGrid();
}

Tile * Grid::getTile() {
	return _tile;
}

void Grid::addUnit(Unit * unit) {
    if (_unit != nullptr) {
        std::cout << "Añadiendo Unit a Grid con Unit previa (" << _posX << ", " << _posY << ")" << std::endl;
        return;
    }
    _unit = unit;
    // TODO: Cambiar el _coste de Grids contiguos al emplazar una Torre, actualizar también el removeUnit acorde a los cambios.
}

void Grid::removeUnit(Unit * unit) {
    _unit = nullptr;
    unit->detatchFromGrid();
}

Unit * Grid::getUnit() {
	return _unit;
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

void Grid::draw(sf::RenderTexture & imagenMapa) {
	if (_tile != nullptr) {
		imagenMapa.draw(_tile->getSprite());
	}
}
