#pragma once
#include "../unit.h"

#include <SFML/Graphics/CircleShape.hpp>

/*
    Clase gen�rica para las torres.
*/
class Torre : public Unit {
private:
    bool mouseIsOver;   ///< True si el rat�n est� encima de esta Torre.
    sf::CircleShape rangeCircle;    ///< RangeCircle que muestra el rango de la Torre.
    void initRangeCircle();         ///< Inicializa el RangeCircle.
    float range = 150.0f;           ///< Rango efectivo de la Torre.

public:
    Torre();
    ~Torre();
    
    // General
    /*
        Est� el rat�n encima de esta Torre?
    */
    bool checkMouseOver();
    bool onTick(const float elapsed);

    // Pathfinding
    /*
    Cuanto cuesta poder caminar sobre la unidad.
    */
    int getWalkCost();
    /*
    Cuanto le cuesta al Enemigo* caminar sobre esta unidad.
    */
    int getWalkCostFor(Enemigo* enemigo);
};

