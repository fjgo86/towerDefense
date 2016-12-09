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

            if (loginStatus == ACM_Ok) {

                std::cout << "login = ACM_Ok" << std::endl;
                lobbyConnection->getConnection()->setNetworkStatus(ConnectionManager::Connected);
            }


        }
        else {
            _ERRORLOG("Error recibiendo loginStatus.\n");
        }
    }
}
