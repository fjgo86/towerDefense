#pragma once
#include "Game\UnitManager.h"
#include "Game\ColectorBasura.h"

/*
	Clase que se encarga de manejar el tiempo de juego, el flujo de objetos, su interacci�n...
	TODO: Meter aqu� un controlador de teclas, etc
*/
class GameManager
{
private:
	UnitManager* listadoEnemigos;
	UnitManager* listadoTorres;
	ColectorBasura* gbcEnemigos;
	ColectorBasura* gbcTorres;
public:
	GameManager();
	~GameManager();
	void onTick();
};

