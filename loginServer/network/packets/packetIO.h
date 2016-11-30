#pragma once
#include "packetIn.h"
#include "packetOut.h"

class PacketIO : public PacketIn, public PacketOut {
    PacketIO(PacketID id);
    ~PacketIO();
};