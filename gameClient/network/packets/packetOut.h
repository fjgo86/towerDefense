#pragma once
#include "packet.h"

/*
* @brief Clase Packet que solo puede enviar datos.
*/
class PacketOut : public Packet {
private:
    int _id;
    std::vector<char> myBuffer;
public:
    PacketOut(PacketID id); // ID del paquete a enviar.
    ~PacketOut();
};