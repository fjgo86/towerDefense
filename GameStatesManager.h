#pragma once
#include "GameState.h"
#include <deque>

class GameStatesManager
{
private:
	//std::stack<GameState*> estados;
    std::deque<GameState*> estados;

public:

	GameState* getEstadoActual();
	void setEstadoActual(GameState* estado);

	GameStatesManager();
	~GameStatesManager();
};

