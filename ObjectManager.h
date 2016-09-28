#pragma once

#include <vector>
#include "ObjBase.h"

/*
	@Brief: Clase que se encarga de recorrer todos los Objetos existentes en el juego y de hacerles saber que tienen que hacer cosas.
*/
extern class ObjectManager
{
private:
	std::vector<ObjBase*> mList;	// Lista vectoriana que almacena todos los Objetos din�micos existentes.
public:
	ObjectManager();
	~ObjectManager();
	/*
		@Brief: A�ade un elemento a la lista.
	*/
	void add(ObjBase* obj);

	/*
		@brief: Borra un elemento de la lista.
	*/
	void remove(ObjBase* obj);

	/*
		@Brief: Loop que recorre todos los objetos y les hace un onTick, para que hagan sus cosas.
	*/
	void onTick();
} gObjManager;

