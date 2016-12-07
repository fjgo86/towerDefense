#pragma once

#include <SFML/Network/Packet.hpp>
#include <networking/packetOut.h>

class Client;

class PacketLoginReq : public PacketOut {
public:
    PacketLoginReq(std::string user, std::string pw);
	~PacketLoginReq();
};

