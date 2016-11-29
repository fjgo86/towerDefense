#pragma once
#include <vector>

#include <SFML/Network.hpp>

class Client;
/*
* brief Clase que se encarga de todo lo relacionado con la red
* Esta clase se encarga de recibir y almacenar nuevos clientes,
* as� como de enviar peri�dicamente los datos que estos necesiten
* y de recibir cualquier dato que generen.
*/
class Network {
private:
    sf::TcpListener _listener;	///< Clase que se mantiene a la espera de los datos recibidos.
    std::vector<Client*> _clients;	///< Clase que guarda un listado de todos los Clients conectados.
public:
    Network();
    ~Network();
    /*
    * brief Ejecuta un tick.
    Ejecuta un tick en todo el network, encargandose de recibir nuevos clients as� como enviar y recibir datos
    */
    void onTick();

    /*
    * @Brief A�ade un Client.
    * A�ade un Client al vector _clients.
    * @param *client: El client a a�adir.
    */
    void addClient(Client *client);

    /*
    * @Brief Borra un Client.
    * Borra un Client al vector _clients.
    * @param *client: El client a borrar.
    */
    void deleteClient(Client *client);
    /*
    * @Brief Actualiza la lista de clients.
    * Actualiza el vector _clients tras el borrado de alg�n Client previo.
    */
    void updateClients();
};