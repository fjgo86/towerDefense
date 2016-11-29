#pragma once

#include <iostream>

#include "ViewsWrapper.h"

class ConnectionManager : public ViewsWrapper {
private:
    sf::Font _fuente;
    sf::Text _statusText;
    char _networkStatus;

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

    // Devuelve el estado de la conexión.
    char getNetworkStatus();
    // Cambia el estado de la conexión. (Solo para debug, el estado más adelante se gestionará desde la propia clase)
    void setNetworkStatus(char status);

    void onTick();
    void handleInput(sf::Event &event);
};

