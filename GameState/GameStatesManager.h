#pragma once
#include <deque>

#include "GameState.h"

class GameStatesManager {
private:
	//std::stack<GameState*> estados;
    std::deque<GameState*> estados;

public:

	GameState* getEstadoActual();
	void setEstadoActual(GameState* estado);

	GameStatesManager();
	~GameStatesManager();
};

