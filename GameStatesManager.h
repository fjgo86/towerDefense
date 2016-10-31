#pragma once
#include "GameState.h"
#include <stack>

class GameStatesManager
{
private:
	std::stack<GameState*> estados;

public:

	GameState* getEstadoActual();
	void setEstadoActual(GameState* estado);

	GameStatesManager();
	~GameStatesManager();
};

