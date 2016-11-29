#pragma once
#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include "grid.h"

#define COORD(x, y) std::pair<unsigned int, unsigned int>(x, y) // Acceso directo al Pair de las coordenadas.

/*
    Clase que se encarga de la parte interna del mapeado
*/
class Map : public std::map<std::pair<unsigned int, unsigned int>, Grid*> {
private:
    unsigned int _maxX; ///< Cantidad máxima de casillas X.
    unsigned int _maxY; ///< Cantidad máxima de casillas Y.
    unsigned int _tileSize = 32;    ///< Tamaño de los tiles: 32x32 pixeles
    void generaMapa();
	sf::RenderTexture _imagenMapa;
	sf::Sprite _spriteMapa;
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
    Devuelve el Grid que se situa en los pixeles especificados ( El Grid que está bajo el ratón ).
    */
    Grid* getGridFromPixel(unsigned int x, unsigned int y);
	/*
	Dibuja el contenido de _imagenMapa en la ventana principal.
	*/
    void draw();
	/*
	Borra el contenido de _imagenMapa y/o lo dibuja desde 0.
	*/
	void reset();
};

