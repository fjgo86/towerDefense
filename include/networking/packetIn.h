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
    * @brief: Método usado para recuperar los datos del paquete.
	* @param theClient puntero al Client del programa para ejecutar sobre él cualquier cambio oportuno en su estado.
	* @param _data con el array de datos que aun quede dentro del paquete.
    */
    virtual void doReceive(Client *theClient, sf::Packet _data) = 0;
};