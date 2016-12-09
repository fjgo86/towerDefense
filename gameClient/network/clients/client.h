#pragma once
#include <SFML/Network.hpp>

#include <../gameClient/gamestates/menu/state_lobby.h>

class Network;
class Account;

/*
* @brief Clase que guarda la conexi�n TCP con el Servidor.
* Esta clase, que hereda de sf::TcpSocket se encarga de guardar la conexi�n con el servidor y de enviar, recibir e interpretar futuros datos a trav�s de ella.
*/
class Client : public sf::TcpSocket {
public:
    /*
    * @brief Estado de la conexi�n del cliente con respecto al servidor.
    */
    enum CONNECTION_TYPE {
        CT_CONNECTING,
        CT_CONNECTED,
        CT_DISCONNECTED
    };

private:
	int _id;                    ///< ID que apunta a la posici�n del Client en el vector Network::_clients<Client*>
	sf::Clock _lastActivity;    ///< Registro de tiempo de la �ltima actividad del cliente (Timeout, control de in/actividad ...).
    CONNECTION_TYPE _connType;

    LobbyState* lobbyConnection;

public:
	Client();
	~Client();
	/*
	* @Brief Se recibe un paquete del servidor.
	* Se ha recibido un paquete de datos por parte del Servidor.
	* param id del paquete.
	* param data con el Packet recibido.
	*/
	void receivePacket(int id, sf::Packet data);
    /*
    * @brief Realiza un intento de conexi�n con el servidor.
    */
    void doConnect();
	/*
	* @brief Conexion.
	* El Client acaba de conectarse al servidor.
	*/
	void onConnect();
	/*
	* @brief Desconexi�n.
	* El Client se acaba de desconectar del servidor.
	*/
	void onDisconnect();
	/*
	* @brief Ejecuta un Tick.
	* Ejecuta un Tick en el cliente, renovando el _lastActivity y comprobando la entrada de nuevos Packets por parte del servidor.
	*/
	void onTick();
    /*
    * @brief Obtener estado de la conexi�n.
    * Obtiene el estado de la conexion, de tipo CONNECTION_TYPE
    */
    CONNECTION_TYPE getConnType();
};

