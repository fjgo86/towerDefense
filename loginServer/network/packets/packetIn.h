#pragma once
#include "packet.h"

/*
* @brief Clase Packet que solo recibe datos.
*/
class PacketIn : public Packet {
public:
    PacketIn();
    ~PacketIn();
};