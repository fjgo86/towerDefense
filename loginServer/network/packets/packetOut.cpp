#include "packetOut.h"
#include "../logger/log.h"

PacketOut::PacketOut(PacketID id) {
    (*this) << id;
}

PacketOut::~PacketOut() {
}
