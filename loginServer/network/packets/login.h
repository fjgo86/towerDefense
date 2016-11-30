#pragma once

#include <SFML/Network.hpp>
#include "packetOut.h"

class Client;
class Account;

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

	PacketLogin(Client *client, sf::Packet data);
	~PacketLogin();

    /*
    * @brief Lee el contenido del Packet
    * Lee el usuario y la contraseña enviados a través del Packet.
    * return false si hay algún tipo de fallo o problema.
    */
    bool readPacket(sf::Packet data, std::string &user, std::string &pw);

    /*
    * @brief Comprueba si existe esa cuenta.
    * Hace un llamado a la Base de Datos buscando una cuenta que coincida con ese usuario y contraseña
    * Crea una Account en caso de encontrar algún resultado.
    * @return AccConnectMsg
    */
    AccConnectMsg checkAccount(std::string user, std::string pw, Account *cuenta);
};

