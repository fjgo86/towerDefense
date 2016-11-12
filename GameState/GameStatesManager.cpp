#include <iostream>

#include "GameStatesManager.h"
#include "../Game/GameManager.h"
#include "../Menu/MainMenuManager.h"

GameStatesManager::GameStatesManager() {

    _gameStarted = false;
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
    std::cout << "Destructor de GameStatesManager" << std::endl;
}