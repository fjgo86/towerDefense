
#include <logger\logger.h>

#include "serverListener.h"
#include "../networking/packets.h"
#include "../networking/config.h"
#include "clients/client.h"
#include "packets/login.h"
#include "packets/packetOut.h"

ServerListener::ServerListener() {
    if (listen(5300) == sf::Socket::Done) {
        _LOG(Log::LOGLVL_EVENT, "Socket conectado \n");
    }
    else{
        _ERRORLOG("No se puede conectar al socket \n");
    }
    setBlocking(false);
}

ServerListener::~ServerListener() {
    close();
    for (int i = 0; i < _clients.size(); i++) {
	    Client *client = _clients[i];
	    if (client)
            delete client;
    }
    _clients.clear();
}

void ServerListener::addClient(Client * client) {
    _clients.push_back(client);
}

void ServerListener::deleteClient(Client * client) {
    _clients.erase(_clients.begin() + client->getID());
    updateClients();
}

void ServerListener::updateClients() {
    for (int i = 0; i < _clients.size(); i++) {
        if (_clients[i])
            _clients[i]->setID(i);
        else {
            // Error: no debería de darse este caso.
            _ERRORLOG("Borrando client inexistente '" << i << "'.\n");
        }
    }
}

void ServerListener::onTick() {
    Client *client = new Client();// Creo un Client
    if (accept(*client) == sf::Socket::Done) {	// y lo transformo en la nueva conexión recibida
        client->setID((int)_clients.size());	// Asignación de ID del nuevo client.
        client->onConnect();
        addClient(client);
    }

    if (_clients.size() <= 0) {
        return;
    }

    for (int i = 0; i < _clients.size(); i++) {
        //if (_clients[i] != nullptr)
	        _clients[i]->onTick();
    }
}