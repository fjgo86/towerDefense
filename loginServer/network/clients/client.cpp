#include "Client.h"

#include <SFML/System.hpp>
#include <logger/logger.h>
#include <networking/packets.h>

#include "../../loginServer.h"
#include "../packets/loginReq.h"

Client::Client() {
	_lastActivity.restart();
    setBlocking(false);
}


Client::~Client() {
}

int Client::getID() {
	return _id;
}

void Client::setID(int id) {
	_id = id;
	// TODO: Security checks con respecto al vector.
}

Account * Client::getAccount() {
    return _cuenta;
}

void Client::setAccount(Account * cuenta) {
    _cuenta = cuenta;
}

void Client::receivePacket(int id, sf::Packet data) {
	switch (id) {
        default:
            _ERRORLOG("Reciviendo Packet inexistente: " << id);
            break;
		case LoginReq:
			_LOG(Log::LOGLVL_EVENT, "Recibido packetLogin");
			PacketLoginReq* thePacket = new PacketLoginReq();
            thePacket->doReceive(this, data);
            delete thePacket;

	}
	_lastActivity.restart();
}

void Client::onConnect() {
	_LOG(Log::LOGLVL_EVENT, "Client " << getID() << "conectado desde " << std::string(getRemoteAddress().toString()));
}

void Client::onDisconnect() {
	_LOG(Log::LOGLVL_EVENT, "Client " << getID() << " desconectado.");
	close();
	//gServer._network->deleteClient(this);
}

void Client::onLogin() {
    // TODO: Envíar un packet con contenido para el Lobby.
}

void Client::onTick() {
	//_LOG(Log::LOGLVL_EVENT, "onTick en Client " << getID() << ".\n");


    sf::Packet packet;
    if (receive(packet) == sf::Socket::Status::Done) {
        _EVENTLOG("Packet recibido");
        int packetID;
        packet >> packetID;
        receivePacket(packetID, packet);
    }

	if (getRemoteAddress() == sf::IpAddress::None && _lastActivity.getElapsedTime().asSeconds() > 10.0f) {
		_LOG(Log::LOGLVL_EVENT, "Client " << getID() << " afk.");
		onDisconnect();
	}
}
