#include "Client.h"

#include <SFML/System.hpp>

#include <logger/logger.h>

#include <networking/packets.h>
#include <networking/config.h>
#include "../packets/loginReq.h"
#include "../packets/loginResp.h"
#include <../gameClient/game.h>

Client::Client() {
    setBlocking(false);
    _connType = CT_DISCONNECTED;

    lobbyConnection = static_cast<LobbyState*>(gGame._statesManager->getEstadoActual());
}

Client::~Client() {
}

void Client::receivePacket(int id, sf::Packet data) {
    switch (id) {
        default:
            _ERRORLOG("Client::receivePacket: Paquete '" << id << "' sin registrar.\n");
            return;
        case LoginResp:
            PacketLoginResp* pResp = new PacketLoginResp();
            pResp->doReceive(this, data);
            delete pResp;
            return;
    }
}

void Client::doConnect() {
    if (_connType == CT_DISCONNECTED) { // No se intenta la conexión a menos que el socket esté desconectado.
        _LOG(Log::LOGLVL_EVENT, "Conectando con el servidor.\n");

        lobbyConnection->getConnection()->setStatusText("Conectando con el servidor");
        lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Connecting);

        _connType = CT_CONNECTING;
        connect(sf::IpAddress(SERVERIP), SERVERPORT);
        _lastActivity.restart();
    }
}

void Client::onConnect() {
    _LOG(Log::LOGLVL_EVENT, "Conectado con el servidor.\n");

    lobbyConnection->getConnection()->setStatusText("Conectado con el servidor");
    lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Connecting);

    _connType = CT_CONNECTED;
    _lastActivity.restart();
}

void Client::onDisconnect() {
	_LOG(Log::LOGLVL_EVENT, "Desconectado del servidor.\n");

    lobbyConnection->getConnection()->setStatusText("Conectado con el servidor");
    lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Disconnected);

    _connType = CT_DISCONNECTED;
	close();
}

void Client::onTick() {
    // Comprobación del éxito de la conexión
    if (_connType == CT_CONNECTING && getRemoteAddress() == sf::IpAddress(SERVERIP) && this->getLocalPort() != 0) {
        onConnect();
    }

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

Client::CONNECTION_TYPE Client::getConnType() {

    return _connType;
}
