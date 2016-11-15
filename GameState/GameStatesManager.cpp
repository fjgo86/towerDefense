#include <iostream>

#include "GameStatesManager.h"
#include "../Game/GameManager.h"
#include "../Menu/MainMenuManager.h"
#include "../Menu/LoginState.h"

GameStatesManager::GameStatesManager() {

    _gameStarted = false;
}

void GameStatesManager::initEstados() {
 
    this->estados["game"] = new GameManager();
    this->estados["menu"] = new MainMenuManager();
    this->estados["login"] = new LoginState();
}

GameState* GameStatesManager::getEstadoActual() {

    return this->estadoActual;
}

std::string GameStatesManager::getEstadoActualNombre() {

    return this->estadoActual->nombreEstado;
}

void GameStatesManager::setEstadoActual(std::string estado) {

    this->estadoActual = this->estados[estado];
    this->estadoActual->nombreEstado = estado.c_str();

    std::cout << "Estados: " << this->estados.size() << std::endl;
    std::cout << "Estado Actual: " << getEstadoActualNombre() << std::endl;
}

void GameStatesManager::newGame(bool iniciarAutomaticamente) {

    // TODO: Comprobar que no se hace un delete null
    delete this->estados["game"];
    this->estados["game"] = new GameManager();

	if (iniciarAutomaticamente) {

		this->setEstadoActual("game");
		_gameStarted = true;
	}
}

bool GameStatesManager::isGameStarted() {

    GameManager* game = (GameManager*)this->estados["game"];
    return game->getGameStarted();
}

GameStatesManager::~GameStatesManager() {
}