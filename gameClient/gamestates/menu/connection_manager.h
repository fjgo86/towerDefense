#pragma once

#include <iostream>

#include "ViewsWrapper.h"

class ConnectionManager : public ViewsWrapper {
private:
    sf::Font _fuente;
    sf::Text _statusText;
    short _networkStatus;

public:
    enum NetworkStatus {
        Disconnected,
        Connecting,
        Connected,
        NetworkStatusQTY
    };

public:
    ConnectionManager();
    ~ConnectionManager();

    // Devuelve el estado de la conexi�n.
    short getNetworkStatus();
    // Cambia el estado de la conexi�n. (Solo para debug, el estado m�s adelante se gestionar� desde la propia clase)
    void setNetworkStatus(short status);

    void onTick();
    void handleInput(sf::Event &event);
};
