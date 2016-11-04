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
    AnimatedSprite animatedSprite;      ///< Enlace a la animación del objeto.
public:
	Unit();
	~Unit();
	void draw(const float elapsed);							///< Método que dibuja el objeto en la pantalla.
	virtual bool onTick(const float elapsed) = 0;

	// SETTERS
	void setNombre(const char* nombreNuevo);				///< Método que asigna un nombre al objeto.
	void setRutaImagen(const char* ruta);					///< Método que asigna una ruta para la Imagen del objeto y genera su AnimatedSprite.
	void setPosition(float x, float y);						///< Método que asigna la posición del sprite
	void setOrigin(bool centered = true);					///< Método que mueve el origen de la esquina top-left al center del sprite
	void setOrigin(float x, float y);						///< Método sobrecargado para mover el origen a las coordenadas especificadas

	// GETTERS
	const char* getNombre();								///< Método que devuelve el nombre del objeto.
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