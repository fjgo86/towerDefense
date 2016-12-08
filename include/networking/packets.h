#pragma once

/*
* @brief ID de los paquetes (el mismo para client y para server).
* NOTA: Evitar usar ID < 10 para evitar problemas con varios checks de SFML.
*/
enum PacketID {
	LoginReq = 1050,
    LoginResp
};