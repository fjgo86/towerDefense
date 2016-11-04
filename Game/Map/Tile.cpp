#include "Tile.h"
#include "Grid.h"
#include <iostream>

Tile::Tile() {
}


Tile::~Tile() {
}

void Tile::attatchToGrid(Grid* grid, bool isBorderTile) {
    _grid = grid;
    sfTexture.loadFromFile("media/Tiles/tile_gris_1.png");
    sfSprite.setTexture(sfTexture);

    if (isBorderTile)
        sfSprite.setColor(sf::Color::Black);    // TODO cambiar esto para que muestre otro tile en vez de colorearlo (cosa que no hace).

    sfSprite.setPosition(_grid->_posX * 32, _grid->_posY * 32);
}

void Tile::detatchFromGrid() {
    _grid = nullptr;
}

sf::Sprite Tile::getSprite() {
    return sfSprite;
}
