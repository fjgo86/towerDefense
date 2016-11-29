
#include "../logger/log.h"

#include "network.h"
#ifdef _LOGINSERVER
    #include "../loginServer/network/clients/client.h"
#else
    #ifdef _GAMECLIENT
        #include "../gameClient/network/clients/client.h"
    #endif
#endif
#include "packets/listado_paquetes.h"

Network::Network() {
    _listener.setBlocking(false);
    if (_listener.listen(53000) == sf::Socket::Done) {
        _LOG(Log::LOGLVL_EVENT, "Socket conectado \n");
    }
    else{
        _ERRORLOG("No se puede conectar al socket \n");
    }
}

Network::~Network() {
    _listener.close();	
    for (int i = 0; i < _clients.size(); i++) {
	    Client *client = _clients[i];
	    if (client)
            delete client;
    }
    _clients.clear();
}

void Network::addClient(Client * client) {
    _clients.push_back(client);
}

void Network::deleteClient(Client * client) {
    _clients.erase(_clients.begin() + client->getID());
    updateClients();
}

void Network::updateClients() {
    for (int i = 0; i < _clients.size(); i++) {
        if (_clients[i])
            _clients[i]->setID(i);
        else {
            // Error: no debería de darse este caso.
            _ERRORLOG("Borrando client inexistente '" << i << "'.\n");
        }
    }
}

void Network::onTick() {
    Client* client = new Client();// Creo un Client
    if (_listener.accept(*client) == sf::Socket::Done) {	// y lo transformo en la nueva conexión recibida
        client->setID((int)_clients.size());	// Asignación de ID del nuevo client.
        client->onConnect();
        addClient(client);
    }
    else {
        delete client;
    }

    if (!_clients.size())
        return;

    for (int i = 0; i < _clients.size(); i++) {
        if (_clients[i])
	        _clients[i]->onTick();
    }
}