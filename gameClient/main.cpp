#include "Game.h"

Game gGame;
void main() {
    gGame.init();
    while (gGame._gameWindow->isOpen()) {
        gGame._gameWindow->clear();
        gGame.onTick();
        gGame._gameWindow->display();
    }
    return;
}