#pragma once

#include <SFML/Network.hpp>
#include "packet.h"

class Client;

class PacketLogin : public Packet {
public:
    /*
    * @brief Valor devuelto en el intento de conexi�n de una cuenta.
    */
    enum AccConnectMsg {
        ACM_Ok,         // Todo correcto.
        ACM_UserPw,     // Usuario o Contrase�a incorrectas.
        ACM_Block,      // Cuenta bloqueada.
        ACM_BD,         // Fallos de conexi�n con BD.
        ACM_MISC,       // Error leyendo datos del paquete?...
        ACM_QTY
    };

	PacketLogin();
	~PacketLogin();

    /*
    * @brief Lee el contenido del Packet
    * Recibe si el Login fue exitoso o no
    */
    void readPacket(sf::Packet data);

    /*
    * @brief Comprueba si existe esa cuenta.
    * Env�a la informaci�n de la cuenta al servidor para hacer Login
    */
    void checkAccount(std::string user, std::string pw);
};

