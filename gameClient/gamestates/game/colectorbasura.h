#pragma once
#include <vector>

#include "Unit.h"

class UnitManager;
/*
    Clase vectoriana que se ocupa de almacenar los objetos que se van a eliminar y borrarlos de sus respectivos listados.
*/
class ColectorBasura : public std::vector<Unit*> {
public:
    ColectorBasura();
    ~ColectorBasura();
    void onTick(UnitManager* listado);
};