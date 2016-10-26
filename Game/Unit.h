#pragma once
#include "AnimatedSprite.h"

/*
	Clase padre de todas las unidades, enemigas o aliadas.
*/
class Unit
{
protected:
	const char* rutaImagen;			///< Ruta en la que encontrar la Imagen del objeto.
	const char* nombre = "";		///< Nombre del objeto.
private:
	AnimatedSprite animatedSprite;	///< Enlace a la animaci�n del objeto.
public:
	Unit();
	~Unit();
	void draw();					///< M�todo que dibuja el objeto en la pantalla.
	const char* getNombre();		///< M�todo que devuelve el nombre del objeto.
	void setNombre(const char* nombreNuevo);	///< M�todo que asigna un nombre al objeto.
	void setRutaImagen(const char* ruta);		///< M�todo que asigna una ruta para la Imagen del objeto y genera su AnimatedSprite.
};

