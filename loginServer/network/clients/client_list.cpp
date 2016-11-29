#include "../../../logger/log.h"
#include "client_list.h"

ClientList::ClientList() {
}

ClientList::~ClientList() {
	for (int i = 0; i < size(); i++) {
		Client *client = (*this)[i];
		if (client)
			delete client;
	}
	clear();
}

void ClientList::addClient(Client * client) {
	push_back(client);
}

void ClientList::deleteClient(Client * client) {
}
