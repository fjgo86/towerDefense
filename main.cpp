#include "Game.h"


Game gGame; //Creamos una instancia de la clase Game

void main() {
    while (gGame.pGameWindow.isOpen()) {
        gGame.pGameWindow.clear();
        gGame.onTick();
        gGame.pGameWindow.display();
    }
    return;
}