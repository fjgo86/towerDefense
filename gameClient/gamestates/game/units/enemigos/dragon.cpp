#include "dragon.h"
#include "../../../../game.h"

Dragon::Dragon() {
    //int randomNumber = rand() % (4 + 1);

    setNombre("Dragon prueba");
    setRutaImagen("media/unit_dragon.png");
    //animatedSprite.setDireccion(randomNumber);
    animatedSprite.setDireccion(DIR_S);
    animatedSprite._speed = 2.0f;
}


Dragon::~Dragon() {
}
