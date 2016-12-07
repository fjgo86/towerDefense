#pragma once

#include <SFML/Network.hpp>
#include <networking/packetIn.h>

class Client;
class Account;

class PacketLoginReq : public PacketIn {
public:
    /*
    * @brief Valor devuelto en el intento de conexión de una cuenta.
    * Valor que se devuelve al intentar conectar una cuenta.
    * Cualquier valor diferente a ACM_OK detiene el proceso.
    */
    enum AccConnectMsg {
        ACM_Ok,         // Todo correcto.
        ACM_UserPw,     // Usuario o Contraseña incorrectas.
        ACM_Block,      // Cuenta bloqueada.
        ACM_BD,         // Fallos de conexión con BD.
        ACM_MISC,       // Error leyendo datos del paquete.
        ACM_CLIVER,     // Error en la version del cliente.
        ACM_QTY
    };

    PacketLoginReq();
	~PacketLoginReq();

    void doReceive(Client *theClient, sf::Packet theData);

    /*
    * @brief Comprueba si existe esa cuenta.
    * Hace un llamado a la Base de Datos buscando una cuenta que coincida con ese usuario y contraseña
    * Crea una Account en caso de encontrar algún resultado.
    * @return AccConnectMsg
    */
    AccConnectMsg checkAccount(std::string user, std::string pw, Account *theAccount);

    /*
    * @brief Responde al cliente
    */
    void reply(Client *theClient, AccConnectMsg loginStatus);
};

