#include "Client.h"

#include <SFML/System.hpp>

#include "../logger/log.h"

#include "../../../networking/packets.h"
#include "../../../networking/config.h"
#include "../packets/login.h"

Client::Client() {
    setBlocking(false);
    _connType = CT_DISCONNECTED;
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

void Client::receivePacket(int id, sf::Packet data) {

}

void Client::onConnect() {
    if (_connType == CT_DISCONNECTED) {
        _LOG(Log::LOGLVL_EVENT, "Conectado con el servidor.\n");
        _connType = CT_CONNECTING;
        connect(sf::IpAddress(SERVERIP), 5300);
        _lastActivity.restart();
    }
}

void Client::onDisconnect() {
	_LOG(Log::LOGLVL_EVENT, "Desconectado del servidor.\n");
    _connType = CT_DISCONNECTED;
	close();
}
void Client::onTick() {
	//_LOG(Log::LOGLVL_EVENT, "onTick en Client " << getID() << ".\n");


    sf::Packet packet;
    if (receive(packet) == sf::Socket::Status::Done) {
        int packetID;
        packet >> packetID;
        receivePacket(packetID, packet);
    }

	if (_connType != CT_DISCONNECTED && (getRemoteAddress() == sf::IpAddress::None || _lastActivity.getElapsedTime().asSeconds() > 10.0f)) {
		onDisconnect();
	}
}
