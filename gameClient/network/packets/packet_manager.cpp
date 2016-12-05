#include "packet_manager.h"


PacketManager::PacketManager() {
}

PacketManager::~PacketManager() {
}

void PacketManager::registerAll() {
}

void PacketManager::registerPacket(PacketID id, Packet* packet) {
    unregisterPacket(id);
    packetList[id] = packet;
}

void PacketManager::unregisterPacket(PacketID id) {
    if (packetList[id] == nullptr)
        return;
    delete packetList[id];
}

Packet * PacketManager::getPacket(PacketID id) {
    if (packetList[id] == nullptr)
        return nullptr;
    return packetList[id];
}
