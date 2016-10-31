#pragma once
#include "../Unit.h"
#include "../../Game.h"

/*
	Clase genérica para las torres.
*/
class Torre : public Unit
{
private:
	bool mouseIsOver;
	sf::CircleShape rangeCircle;
	void initRangeCircle();

public:

	bool checkMouseOver();

	Torre();
	~Torre();

	bool onTick(const float elapsed);
};

