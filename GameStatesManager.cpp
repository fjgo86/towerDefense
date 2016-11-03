#include "GameStatesManager.h"
#include "GameManager.h"
#include <iostream>

GameStatesManager::GameStatesManager()
{
}

GameState* GameStatesManager::getEstadoActual()
{
	//return this->estados.top();
    return this->estados.front(); // Devuelve el primer elemento del deque
}

void GameStatesManager::setEstadoActual(GameState* estado)
{
    auto estadoBuscado = std::find(this->estados.begin(), this->estados.end(), estado);
    
    if (estadoBuscado == this->estados.end()) {
    
        std::cout << "El estado no existe, lo voy a crear con ID = " << estado << std::endl;
        this->estados.push_front(estado);
    }
    else {

        std::cout << "El estado ya existe y tiene la ID = " << estado << ", lo voy a activar." << std::endl;
        this->estados.front() = estado;
    }

    std::cout << "Estados: " << this->estados.size() << std::endl;
}

GameStatesManager::~GameStatesManager()
{
}
