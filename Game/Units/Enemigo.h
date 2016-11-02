#pragma once
#include "../Unit.h"

/*
	Clase genérica para los enemigos.
*/
class Enemigo : public Unit
{
protected:
    bool _canFly; ///< Puede volar esta unidad?
public:
	Enemigo();
	~Enemigo();

    // General

	bool onTick(const float elapsed);

    // Pathfinding
    /*
        Puede volar esta unidad?
    */
    bool canFly();
    /*
        Cuanto cuesta poder caminar sobre la unidad.
    */
    int getWalkCost();
    /*
        Cuanto le cuesta al Enemigo* caminar sobre esta unidad.
    */
    int getWalkCostFor(Enemigo* enemigo);
};

