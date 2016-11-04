#pragma once
class GameState
{
public:

	virtual void handleInput() = 0;
	virtual void onTick() = 0;

	GameState();
	~GameState();
};

