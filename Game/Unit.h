#pragma once
#include "AnimatedSprite.h"

// Refencias externas.
class Grid;
class Enemigo;

/*
	Clase padre de todas las unidades, enemigas o aliadas.
*/
class Unit {
private:
    Grid* _grid;
protected:
	const char* _rutaImagen;            ///< Ruta en la que encontrar la Imagen del objeto.
	const char* _nombre = "";           ///< Nombre del objeto.
    AnimatedSprite animatedSprite;      ///< Enlace a la animaci�n del objeto.
public:
	Unit();
	~Unit();
	void draw(const float elapsed);							///< M�todo que dibuja el objeto en la pantalla.
	virtual bool onTick(const float elapsed) = 0;

	// SETTERS
	void setNombre(const char* nombreNuevo);				///< M�todo que asigna un nombre al objeto.
	void setRutaImagen(const char* ruta);					///< M�todo que asigna una ruta para la Imagen del objeto y genera su AnimatedSprite.
	void setPosition(float x, float y);						///< M�todo que asigna la posici�n del sprite
	void setOrigin(bool centered = true);					///< M�todo que mueve el origen de la esquina top-left al center del sprite
	void setOrigin(float x, float y);						///< M�todo sobrecargado para mover el origen a las coordenadas especificadas

	// GETTERS
	const char* getNombre();								///< M�todo que devuelve el nombre del objeto.
	sf::FloatRect getFloatRect();
	sf::Vector2f getPosition();
	sf::Vector2f getOrigin();
	int getDireccion();

    // Grid
    void attatchToGrid(Grid* grid);
    void detatchFromGrid();

    // Pathfinding
    virtual int getWalkCost() = 0;
    virtual int getWalkCostFor(Enemigo* unit) = 0;

};