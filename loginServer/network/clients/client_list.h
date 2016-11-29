#pragma once
#include <SFML/Network.hpp>

#include "client.h"
#include <vector>

class ClientList : public std::vector<Client*> {
public:
	ClientList();
	~ClientList();
	/*
	* @Brief A�ade un Client.
	* A�ade un Client al vector de la lista.
	* @param *client: El client a a�adir.
	*/
	void addClient(Client *client);

	/*
	* @Brief Borra un Client.
	* Borra un Client al vector de la lista.
	* @param *client: El client a borrar.
	*/
	void deleteClient(Client *client);
};

