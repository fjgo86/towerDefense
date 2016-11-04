#include "UnitManager.h"
#include "../ColectorBasura.h"
#include <iostream>



UnitManager::UnitManager()
{
	clear();
}


UnitManager::~UnitManager()
{
	// Borrado de todos los objetos existentes y vaciado de sus contenedores.
	while (size())
	{
		Unit* pUnit = back();
		delete pUnit;
		pop_back();
	}
}

void UnitManager::onTick(ColectorBasura* gbc, const float elapsed)
{
	// Tick en los Enemigos.
	if (size())
	{
		for (unsigned int i = 0; i < size(); i++)
		{
			Unit* pUnit = at(i);
			if (pUnit)
			{
				if (!pUnit->onTick(elapsed))				// Si el tick no es true, ese objeto se destruye.
				{
					gbc->push_back(pUnit);	// Se añade al colector de basura para borrarlo posteriormente.
					continue;
				}
			}
		}
	}
}

void UnitManager::addUnit(Unit * unit)
{
	push_back(unit);			// Añade la Unit al final del vector.
}

void UnitManager::borraUnit(Unit * unit)
{
	for (unsigned int i = 0; i < size(); i++)			// Recorre todas las torres.
	{
		if (at(i) == unit)						// Compara las torres una a una, buscando la que se pide.
		{
			erase(begin() + i);	// Borra la entrada correspondiente en el listado una vez la encuentra.
			break;
		}
	}
	delete unit;	// Borra la torre definitivamente de la memoria.
}


