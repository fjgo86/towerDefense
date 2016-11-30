#pragma once
#include <SFML/Network.hpp>

class Network;
class Account;

/*
* @brief Clase que guarda las conexiones TCP
* Esta clase, que hereda de sf::TcpSocket se encarga de guardar la conexi�n recibida y de recibir e interpretar futuros datos a trav�s de ella.
*/
class Client : public sf::TcpSocket {
private:
    enum CONNECTION_TYPE {
        CT_CONNECTING,
        CT_CONNECTED,
        CT_DISCONNECTED
    };

	int _id; ///< ID que apunta a la posici�n del Client en el vector Network::_clients<Client*>
	sf::Clock _lastActivity; ///< Registro de tiempo de la �ltima actividad del cliente (Timeout, control de in/actividad ...).
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
    * Especifica la ID de este Client, puede ser la que se le da al crearse o una modificaci�n por que se haya eliminado alg�n otro Client previo.
    * Siempre debe apuntar a la posici�n del Cliente
    * @param ID informa de la posici�n del Client.
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
	* @brief Desconexi�n.
	* El Client se acaba de desconectar.
	*/
	void onDisconnect();
	/*
	* @brief Ejecuta un Tick.
	* Ejecuta un Tick en el cliente, actualmente para controlar el _lastActivity.
	*/
	void onTick();
};

