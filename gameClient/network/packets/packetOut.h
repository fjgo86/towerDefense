#pragma once
#include <SFML\Network\Packet.hpp>
#include "../networking/packets.h"

class PacketOut : public sf::Packet {
public:
    PacketOut(PacketID id);
    ~PacketOut();
};