#include "loginResp.h"
#include <string>
#include <logger\logger.h>

#include <networking/packets.h>


PacketLoginResp::PacketLoginResp() {
}

PacketLoginResp::~PacketLoginResp() {
}

void PacketLoginResp::doReceive(Client* theClient, sf::Packet data) {
    int rawLoginStatus;
    if (data >> rawLoginStatus) {
        AccConnectMsg loginStatus = (AccConnectMsg)rawLoginStatus;
        _EVENTLOG("Login recibido = " << rawLoginStatus << "\n");

    }
    else {
        _ERRORLOG("Error reciviendo loginStatus.\n");
    }
}
