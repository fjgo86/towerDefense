#pragma once
#include "../Unit.h"

class ColectorBasura;
/*
	Clase que guarda un listado de Unit*.
*/
class UnitManager : public std::vector<Unit*>
{
private:

public:
	UnitManager();
	~UnitManager();
	void onTick(ColectorBasura* gbc, const float elapsed);		///< Control del tiempo.
	void addUnit(Unit* unit);				///< Añade una Unit* a la lista.
	void borraUnit(Unit* unit);				///< Borra la Unit* de la lista.
};

