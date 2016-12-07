#include "packetOut.h"
#include <logger\logger.h>

PacketOut::PacketOut(PacketID id) {
}

PacketOut::~PacketOut() {
}

void PacketOut::insertHeader(PacketID id) {
    (*this) << id;
}
