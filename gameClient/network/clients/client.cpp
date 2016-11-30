#include "Client.h"

#include <SFML/System.hpp>

#include "../logger/log.h"

#include "../../../networking/packets.h"
#include "../../../networking/config.h"
#include "../packets/login.h"

Client::Client() {
    setBlocking(false);
    _connType = CT_DISCONNECTED;
	_lastActivity.restart();
    onConnect();
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
	_LOG(Log::LOGLVL_EVENT, "Conectado con el servidor.\n");
    _connType = CT_CONNECTING;
    connect(sf::IpAddress(SERVERIP) , 5300);
}

void Client::onDisconnect() {
	_LOG(Log::LOGLVL_EVENT, "Desconectado del servidor.\n");
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

	if (_connType == CT_CONNECTED && (getRemoteAddress() == sf::IpAddress::None || _lastActivity.getElapsedTime().asSeconds() > 600.0f)) {
		onDisconnect();
	}
}
