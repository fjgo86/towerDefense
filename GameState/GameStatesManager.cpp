#include <iostream>

#include "GameStatesManager.h"
#include "../Game/GameManager.h"
#include "../Menu/MainMenuManager.h"

GameStatesManager::GameStatesManager() {

    this->initEstados();
}

void GameStatesManager::initEstados() {
 
    this->estados["game"] = new GameManager();
    this->estados["menu"] = new MainMenuManager();
}

GameState* GameStatesManager::getEstadoActual() {

    return this->estadoActual;
}

void GameStatesManager::setEstadoActual(std::string estado) {

    this->estadoActual = this->estados[estado];

    std::cout << "Estados: " << this->estados.size() << std::endl;
}

void GameStatesManager::newGame(bool iniciarAutomaticamente) {

    this->estados["game"] = new GameManager();

    if (iniciarAutomaticamente)
        this->setEstadoActual("game");
}

GameStatesManager::~GameStatesManager() {
}