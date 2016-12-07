#include "packetOut.h"
#include "packets.h"
#include <logger/logger.h>

PacketOut::PacketOut(PacketID id) {
    insertHeader(id);
}

PacketOut::~PacketOut() {
}

void PacketOut::insertHeader(PacketID id) {
    (*this) << id;
}
