#pragma once
#include <string>
#include <networking/packetOut.h>
#include "../clients/client.h"

class PacketLoginResp : public PacketOut {
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

    PacketLoginResp(Client* client, AccConnectMsg status);
	~PacketLoginResp();
};

