#pragma once
#include <SFML/Network.hpp>

class Network;
class Account;

/*
* @brief Clase que guarda las conexiones TCP
* Esta clase, que hereda de sf::TcpSocket se encarga de guardar la conexión recibida y de recibir e interpretar futuros datos a través de ella.
*/
class Client : public sf::TcpSocket {
private:
    enum CONNECTION_TYPE {
        CT_CONNECTING,
        CT_CONNECTED,
        CT_DISCONNECTED
    };

	int _id; ///< ID que apunta a la posición del Client en el vector Network::_clients<Client*>
	sf::Clock _lastActivity; ///< Registro de tiempo de la última actividad del cliente (Timeout, control de in/actividad ...).
    Account *_cuenta;
    CONNECTION_TYPE _connType;
public:
	Client();
	~Client();

    /*
    * @brief Devuelve la ID del este Client.
    * return n ID del Client.
    */
    int getID();
    /*
    * @brief Asigna una ID a este Client.
    * Especifica la ID de este Client, puede ser la que se le da al crearse o una modificación por que se haya eliminado algún otro Client previo.
    * Siempre debe apuntar a la posición del Cliente
    * @param ID informa de la posición del Client.
    */
    void setID(int id);
	/*
	* @Brief Se recibe un paquete del cliente.
	* Se ha recibido un paquete de datos por parte del Client
	* param id del paquete.
	* param data con el Packet recibido.
	*/
	void receivePacket(int id, sf::Packet data);
	/*
	* @brief Conexion.
	* El Client acaba de conectarse.
	*/
	void onConnect();
	/*
	* @brief Desconexión.
	* El Client se acaba de desconectar.
	*/
	void onDisconnect();
	/*
	* @brief Ejecuta un Tick.
	* Ejecuta un Tick en el cliente, actualmente para controlar el _lastActivity.
	*/
	void onTick();
};

