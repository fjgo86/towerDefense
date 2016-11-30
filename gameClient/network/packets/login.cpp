#include "login.h"

#include "../../../logger/log.h"
#include "../../../networking/packets.h"
#include "../clients/client.h"

PacketLogin::PacketLogin() : PacketOut(PACKET_Login) {
}

PacketLogin::~PacketLogin() {
}

bool PacketLogin::readPacket(sf::Packet data) {
    return false;
}

void PacketLogin::checkAccount(std::string user, std::string pw) {
    (*this) >> user >> pw;
}

