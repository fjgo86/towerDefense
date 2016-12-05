#include "packet.h"

Packet::Packet(PacketID id, bool bPacketIn) {
    if (bPacketIn) {
        readHeader(); // Lee el encabezado y lo asigna como Id del paquete.
    }
    else {
        insertHeader(id);
    }
}

Packet::Packet(bool bPacketIn) {
    readHeader();
}

Packet::Packet(PacketID id) {
    insertHeader(id);
}

void Packet::insertHeader(PacketID id) {
    (*this) << id;
}

void Packet::readHeader() {
    *(this) >> _id;
}

Packet::~Packet() {
}
