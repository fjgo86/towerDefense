#pragma once
#include <map>
#include "Grid.h"

#define COORD(x, y) std::pair<unsigned int, unsigned int>(x, y) // Acceso directo al Pair de las coordenadas.

/*
    Clase que se encarga de la parte interna del mapeado
*/
class Map : public std::map<std::pair<unsigned int, unsigned int>, Grid*> {
private:
    unsigned int _maxX; ///< Cantidad m�xima de casillas X.
    unsigned int _maxY; ///< Cantidad m�xima de casillas Y.
    unsigned int _tileSize = 32;    ///< Tama�o de los tiles: 32x32 pixeles
    void generaMapa();

public:
    Map();
    ~Map();

    // Grids
    /*
    Devuelve el Grid correspondiente a las casillas X, Y.
    */
    Grid* getGridAt(unsigned int x, unsigned int y);
    /*
    Devuelve el Grid correspondiente al Pair especificado.
    */
    Grid* getGridAt(std::pair<unsigned int, unsigned int> p);
    /*
    Devuelve el Grid que se situa en los pixeles especificados ( El Grid que est� bajo el rat�n ).
    */
    Grid* getGridFromPixel(unsigned int x, unsigned int y);
    void onTick();
};

