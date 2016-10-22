#pragma once

#include "GameState.h"
#include "../GameObjects/ObjBase.h"
#include "../Gameanimations/AnimatedSprite.h"

enum class ActionState {NONE, HUMAN, FIRE, WATER, BUILDING};

class GameStatePlay : public GameState
{
private:
	ActionState actionState;

	sf::View gameView;
	sf::View guiView;

	void leaveBuildMode();
	ObjBase* objMouseOver;	// El puntero del rat�n se encuentra encima de este objeto din�mico.

	float speed = 80.f;
	bool noKeyWasPressed = true;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStatePlay(Game* game);
	~GameStatePlay();
};

