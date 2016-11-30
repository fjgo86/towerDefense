#pragma once
#include <SFML\Network\Packet.hpp>

class PacketIn : public sf::Packet {
public:
    PacketIn();
    ~PacketIn();

    virtual void receivePacket() = 0;
};