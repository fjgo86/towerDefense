#pragma once
#include "Tile.h"
#include "../Unit.h"

class Grid {
private:
    Tile* _tile;		///< Tile de terreno que hay en este Grid.
    Unit* _unit;		///< Unit que hay en este Grid.
	bool _isBorderGrid;	///< Retorna si este Grid está en el borde del mapa o no.
public:
    unsigned int _posX;		///< Posición X de este Grid.
    unsigned int _posY;		///< Posición Y de este Grid.
	bool isBorderGrid();	///< Devuelve _isBorderGrid;
    Grid(unsigned int x, unsigned int y, bool isBorderGrid);
    ~Grid();

	/*
	Añade un Tile al Grid.
	*/
    void addTile(Tile* tile);
	/*
	Retira un Tile del Grid.
	*/
    void removeTile(Tile* tile);
	/*
	Devuelve el tile del Grid.
	*/
	Tile* getTile();

	/*
	Añade una Unit al Grid.
	*/
    void addUnit(Unit* unit);
	/*
	Retira una Unit del Grid.
	*/
    void removeUnit(Unit* unit);
	/*
	Devuelve la Unit del Grid.
	*/
	Unit* getUnit();

    std::pair<unsigned int, unsigned int> getPosition();    ///< Devuelve un std::pair con la posicion del Grid.

    int getWalkCost();      ///< Devuelve el coste del Grid para el PathFinder.

    void draw(sf::RenderTexture & imagenMapa);
};

