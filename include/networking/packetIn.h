#pragma once
#include <SFML/Network/Packet.hpp>

class Client;

/*
* @brief Clase Packet que solo recibe datos.
*/
class PacketIn {
public:
    PacketIn();
    ~PacketIn();

    /*
    * @brief: M�todo usado para recuperar los datos del paquete.
    */
    virtual void doReceive(Client *theClient, sf::Packet _data) = 0;
};