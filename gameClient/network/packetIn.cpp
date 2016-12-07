#include "packetIn.h"

PacketIn::PacketIn() {
}

PacketIn::~PacketIn() {
}

void PacketIn::readHeader() {
    *(this) >> _id;
}
