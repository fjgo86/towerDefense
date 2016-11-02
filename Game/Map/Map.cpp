#include "Map.h"
#include "../../Game.h"


Map::Map() {
    // Pixeles default del game / pixeles por unidad (default)
    _maxX = gGame.pGameWindow.getSize().x / _tileSize; ///< 1024 / 16 = 64.
    _maxY = gGame.pGameWindow.getSize().y / _tileSize; ///< 720 / 16 / 45.
    // Rellenado del map de la clase
    for (unsigned int x = 0; x < _maxX; x++) {
        for (unsigned int y = 0; y < _maxY; y++) {
            (*this)[COORD(x,y)] = new Grid(x, y, (x == _maxX || y == _maxY) ? true : false);
        }
    }
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

void Map::onTick() {
    iterator it = begin(), final = end();
    while (it != final) {
        Grid * grid = it->second;
        grid->onTick();
        it++;
    }
}
