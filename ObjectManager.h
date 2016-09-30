#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "ObjBase.h"
#include "Game.h"
#include "UID.h"

/*
	@Brief: Clase que se encarga de recorrer todos los Objetos existentes en el juego y de hacerles saber que tienen que hacer cosas.
*/
extern class ObjectManager : public UID
{
private:
	UID* uidManager;
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
	void onTick(Game* game);

	/*
		@brief: Busca un objeto en las coordenadas dadas (generalmente para obtener el objeto en el que se encuentra el cursor del rat�n).
	*/
	ObjBase* findObjectAt(sf::Vector2i pos);

	/*
		@brief: devuelve la siguiente UID libre
	*/
	UID generateUID();
} gObjManager;

