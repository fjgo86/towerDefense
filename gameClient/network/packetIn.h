#pragma once
#include <SFML/Network/Packet.hpp>

/*
* @brief Clase Packet que solo recibe datos.
*/
class PacketIn : public sf::Packet {
private:
    int _id;
public:
    PacketIn();
    ~PacketIn();

    /*
    * @brief: Lee el encabezado del Packet recibido para recuperar el tipo de Packet a ejecutar.
    */
    void readHeader();
};