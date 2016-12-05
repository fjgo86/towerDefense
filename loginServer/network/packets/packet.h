#pragma once
#include <SFML/Network/Packet.hpp>
#include "../networking/packets.h"

/*
* @brief Clase Packet que puede enviar y recibir packets.
*/
class Packet : public sf::Packet {
private:
    int _id;
public:
    Packet(PacketID id, bool bPacketIn);   // Constructor para Packet, PacketIn y PacketOut
    Packet(bool bPacketIn = false); // Constructor para PacketIn
    Packet(PacketID id);            // Constructor para PacketOut
    /*
    * @brief: Inserta como encabezado del Packet la ID del mismo para saber cual procesar en su destino.
    * @param ID del packet.
    */
    void insertHeader(PacketID id);
    /*
    * @brief: Lee el encabezado del Packet recibido para recuperar el tipo de Packet a ejecutar.
    */
    void readHeader();
    ~Packet();
    Packet* getPacket();
};