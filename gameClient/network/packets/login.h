#pragma once

#include <SFML/Network.hpp>
#include "packetOut.h"

class Client;

class PacketLogin : public PacketOut {
public:
    /*
    * @brief Valor devuelto en el intento de conexión de una cuenta.
    * Valor que se devuelve al intentar conectar una cuenta 'AccountsManager::conecta()'
    * Cualquier valor diferente a ACM_OK cancela la conexión.
    */
    enum AccConnectMsg {
        ACM_Ok,         // Todo correcto.
        ACM_UserPw,     // Usuario o Contraseña incorrectas.
        ACM_Block,      // Cuenta bloqueada.
        ACM_BD,         // Fallos de conexión con BD.
        ACM_MISC,       // Error leyendo datos del paquete?...
        ACM_QTY
    };

	PacketLogin();
	~PacketLogin();

    /*
    * @brief Lee el contenido del Packet
    * Recibe si el Login fue exitoso o no
    * return false si hay algún tipo de fallo o problema.
    */
    bool readPacket(sf::Packet data);

    /*
    * @brief Comprueba si existe esa cuenta.
    * Envía la información de la cuenta al servidor para hacer Login
    */
    void checkAccount(std::string user, std::string pw);
};

