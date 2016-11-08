#include "Map.h"

#include "../../Game.h"

#include <iostream>


Map::Map() {
    _imagenMapa.create(gGame._screenWidth, gGame._screenHeight);
    // Pixeles default del game / pixeles por unidad (default)
    _maxX = gGame._gameWindow.getSize().x / _tileSize; ///< 1024 / 16 = 64.
    _maxY = gGame._gameWindow.getSize().y / _tileSize; ///< 720 / 16 / 45.
    // Rellenado del map de la clase
    for (unsigned int x = 0; x < _maxX; x++) {
        for (unsigned int y = 0; y < _maxY; y++) {
            Grid * grid = new Grid(x, y, (x == (_maxX - 1) || y == (_maxY - 1) || x == 0 || y == 0) ? true : false);
            (*this)[COORD(x, y)] = grid;
            grid->draw(_imagenMapa);
        }
    }
    _imagenMapa.display();
    _spriteMapa.setTexture(_imagenMapa.getTexture());
}

Map::~Map() {
    iterator it = begin(), final = end();
    while (it != final) {
        delete it->second;
        it++;
    }
}

void Map::generaMapa() {
    // TODO: Generar bordes exteriores (Impasables).
    // TODO: Generar tiles interiores (Pasables).
}

Grid * Map::getGridAt(unsigned int x, unsigned int y) {
    return (*this)[COORD(x, y)];
}

Grid * Map::getGridAt(std::pair<unsigned int, unsigned int> p) {
    return (*this)[p];
}

Grid * Map::getGridFromPixel(unsigned int x, unsigned int y) {
    unsigned int finalX = x / _tileSize;
    unsigned int finalY = y / _tileSize;
    return getGridAt(finalX, finalY);
}



void Map::draw() {
	gGame._gameWindow.draw(_spriteMapa);
}

void Map::reset() {

	iterator it = begin(), final = end();
	while (it != final) {
		Grid * grid = it->second;
		grid->draw(_imagenMapa);
		it++;
	}
	_imagenMapa.display();
	_spriteMapa.setTexture(_imagenMapa.getTexture());
}
