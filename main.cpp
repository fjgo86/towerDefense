#include "Game.h"


Game gGame; //Creamos una instancia de la clase Game

void main() {
    while (gGame._gameWindow.isOpen()) {
        gGame._gameWindow.clear();
        gGame.onTick();
        gGame._gameWindow.display();
    }
    return;
}