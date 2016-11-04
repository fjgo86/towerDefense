#include <iostream>

#include "Enemigo.h"

Enemigo::Enemigo() {
}


Enemigo::~Enemigo() {
}

bool Enemigo::onTick(const float elapsed) {
    draw(elapsed);
    return true;
}

bool Enemigo::canFly() {
    return _canFly;
}

int Enemigo::getWalkCost() {
    return 5;
}

int Enemigo::getWalkCostFor(Enemigo * enemigo) {
    if (enemigo->canFly() && !canFly())
        return 0;   // Si podemos sobrepasarlos, no nos molestan.
    return enemigo->getWalkCost();
}
