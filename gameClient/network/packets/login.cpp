#include "login.h"

#include <logger\logger.h>
#include "../../../networking/packets.h"
#include "../clients/client.h"

PacketLogin::PacketLogin() : Packet(PACKET_Login) {
}

PacketLogin::~PacketLogin() {
}

void PacketLogin::readPacket(sf::Packet data) {
}

void PacketLogin::checkAccount(std::string user, std::string pw) {
    (*this) << user << pw;
}

