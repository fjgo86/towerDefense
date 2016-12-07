#pragma once
#include <networking/packetIn.h>
#include "../clients/client.h"

class PacketLoginResp : public PacketIn {
public:
    /*
    * @brief Valor devuelto en el intento de conexi�n de una cuenta.
    * Valor que se devuelve al intentar conectar una cuenta.
    * Cualquier valor diferente a ACM_OK detiene el proceso.
    */
    enum AccConnectMsg {
        ACM_Ok,         // Todo correcto.
        ACM_UserPw,     // Usuario o Contrase�a incorrectas.
        ACM_Block,      // Cuenta bloqueada.
        ACM_BD,         // Fallos de conexi�n con BD.
        ACM_MISC,       // Error leyendo datos del paquete.
        ACM_CLIVER,     // Error en la version del cliente.
        ACM_QTY
    };

    PacketLoginResp();
	~PacketLoginResp();

    virtual void doReceive(Client* theClient, sf::Packet data);
};

