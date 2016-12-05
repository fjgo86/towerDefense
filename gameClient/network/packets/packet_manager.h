#pragma once
#include <vector>
#include "packet.h"

/*
* @brief Clase Packet que puede enviar y recibir packets.
*/
class PacketManager {
private:
    std::vector<Packet*> packetList;
public:
    PacketManager();
    ~PacketManager();

    void registerAll();
    void registerPacket(PacketID id, Packet* packet);
    void unregisterPacket(PacketID id);
    Packet* getPacket(PacketID id);
};