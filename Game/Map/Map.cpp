#include "Map.h"


Map::Map() {
    // Pixeles default del game / pixeles por unidad (default)
    _maxX = 64; ///< 1024 / 16 = 64.
    _maxY = 45; ///< 720 / 16 / 45.
    // Rellenado del map de la clase
    for (unsigned int x = 0; x < _maxX; x++) {
        for (unsigned int y = 0; y < _maxY; y++) {
            (*this)[COORD(x,y)] = new Grid();
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
