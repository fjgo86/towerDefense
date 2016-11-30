#pragma once

#include <SFML/Network.hpp>
#include "packetOut.h"

class Client;
class Account;

class PacketLogin : public PacketOut {
public:
    /*
    * @brief Valor devuelto en el intento de conexi�n de una cuenta.
    * Valor que se devuelve al intentar conectar una cuenta 'AccountsManager::conecta()'
    * Cualquier valor diferente a ACM_OK cancela la conexi�n.
    */
    enum AccConnectMsg {
        ACM_Ok,         // Todo correcto.
        ACM_UserPw,     // Usuario o Contrase�a incorrectas.
        ACM_Block,      // Cuenta bloqueada.
        ACM_BD,         // Fallos de conexi�n con BD.
        ACM_MISC,       // Error leyendo datos del paquete?...
        ACM_QTY
    };

	PacketLogin(Client *client, sf::Packet data);
	~PacketLogin();

    /*
    * @brief Lee el contenido del Packet
    * Lee el usuario y la contrase�a enviados a trav�s del Packet.
    * return false si hay alg�n tipo de fallo o problema.
    */
    bool readPacket(sf::Packet data, std::string &user, std::string &pw);

    /*
    * @brief Comprueba si existe esa cuenta.
    * Hace un llamado a la Base de Datos buscando una cuenta que coincida con ese usuario y contrase�a
    * Crea una Account en caso de encontrar alg�n resultado.
    * @return AccConnectMsg
    */
    AccConnectMsg checkAccount(std::string user, std::string pw, Account *cuenta);
};

