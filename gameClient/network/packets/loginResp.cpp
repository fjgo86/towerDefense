#include "loginResp.h"
#include <string>
#include <logger\logger.h>

#include <networking/packets.h>
#include <../gameClient/gamestates/menu/state_lobby.h>
#include <../gameClient/game.h>

PacketLoginResp::PacketLoginResp() {
}

PacketLoginResp::~PacketLoginResp() {
}

void PacketLoginResp::doReceive(Client* theClient, sf::Packet data) {
    
    if (theClient->getConnType() == Client::CT_CONNECTED) {

        int rawLoginStatus;
        if (data >> rawLoginStatus) {
            AccConnectMsg loginStatus = (AccConnectMsg)rawLoginStatus;
            _EVENTLOG("Login recibido = " << rawLoginStatus << "\n");

            LobbyState* lobbyConnection = static_cast<LobbyState*>(gGame._statesManager->getEstadoActual());
            if (!lobbyConnection) { return; }

            switch (loginStatus) {
            case ACM_Ok:
                _EVENTLOG("Login OK");
                lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Connected);
                break;
            case ACM_UserPw:
                _EVENTLOG("Login ERROR: Usuario y/o password no son correctos");
                lobbyConnection->getConnection()->setStatusText("Usuario y/o Password incorrecto/s");
                lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Disconnected);
                break;
            case ACM_Block:
                _EVENTLOG("Login ERROR: La cuenta esta bloqueada");
                lobbyConnection->getConnection()->setStatusText("Esta cuenta esta bloqueada");
                lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Disconnected);
                break;
            case ACM_BD:
                _EVENTLOG("Server ERROR: Ha fallado la conexión con la BD");
                lobbyConnection->getConnection()->setStatusText("Error en la conexión (ACM_BD)");
                lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Disconnected);
                break;
            case ACM_MISC:
                _EVENTLOG("Server ERROR: Error leyendo datos de packet");
                lobbyConnection->getConnection()->setStatusText("Error en la conexión (ACM_MISC)");
                lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Disconnected);
                break;
            default:
                break;
            }

        }
        else {
            _ERRORLOG("Error recibiendo loginStatus.\n");
        }
    }
}
