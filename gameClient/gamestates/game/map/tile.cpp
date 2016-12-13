#include <iostream>

#include "Tile.h"
#include <logger/logger.h>
#include "../../../game.h"
#include "../sprite_manager.h"
#include "Grid.h"

Tile::Tile() {
	try {
		sfTexture = gGame._textureManager->loadFromFile("tile", "../gameClient/media/Tiles/tile_gris_1.png");
		sfSprite.setTexture(*sfTexture);
	}
	catch (...) {
        _LOG(Log::LOGLVL_ERROR, "Error cargando Textura 'tile'.");
		delete this;
		return;
	}
}


Tile::~Tile() {
}

void Tile::attatchToGrid(Grid* grid) {
    _grid = grid;
    if (_grid->isBorderGrid())
		sfSprite.setColor(sf::Color::Black);    // TODO cambiar esto para que muestre otro tile en vez de colorearlo (cosa que no hace).

	sfSprite.setPosition((float)(_grid->_posX * 32), (float)(_grid->_posY * 32));
}

void Tile::detatchFromGrid() {
    _grid = nullptr;
}

sf::Sprite Tile::getSprite() {
    return sfSprite;
}
