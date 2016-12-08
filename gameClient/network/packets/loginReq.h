#pragma once

#include <SFML/Network/Packet.hpp>
#include <networking/packetOut.h>

class Client;

/*
* @brief Query al server buscando una cuenta con el user y password enviado.
*/
class PacketLoginReq : public PacketOut {
public:
    PacketLoginReq(std::string user, std::string pw);
	~PacketLoginReq();
};

