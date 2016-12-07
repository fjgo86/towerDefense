#pragma once
#include <SFML/Network/Packet.hpp>

/*
* @brief Clase Packet que solo puede enviar datos.
*/
class PacketOut : public sf::Packet {
public:
    PacketOut(PacketID id); // ID del paquete a enviar.
    ~PacketOut();
    /*
    * @brief: Inserta como encabezado del Packet la ID del mismo para saber cual procesar en su destino.
    * @param ID del packet.
    */
    void insertHeader(PacketID id)
};