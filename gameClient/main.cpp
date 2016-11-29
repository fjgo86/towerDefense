#include "Game.h"
#include "../logger/logger.h"


Game gGame;
Logger gLog;

void main() {
    gGame.init();
    while (gGame._gameWindow->isOpen()) {
        gGame._gameWindow->clear();
        gGame.onTick();
        gGame._gameWindow->display();
    }
    return;
}