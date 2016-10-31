#include "GameStatesManager.h"
#include "GameManager.h"
#include <iostream>

GameStatesManager::GameStatesManager()
{
}

GameState* GameStatesManager::getEstadoActual()
{
	return this->estados.top();
}

void GameStatesManager::setEstadoActual(GameState* estado)
{
	this->estados.push(estado);
}

GameStatesManager::~GameStatesManager()
{
}
