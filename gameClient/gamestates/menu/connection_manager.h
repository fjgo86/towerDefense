#pragma once

#include <iostream>

#include "ViewsWrapper.h"

class ConnectionManager : public ViewsWrapper {
private:
    sf::Font _fuente;
    sf::Text _statusText, _previousText;
    short _networkStatus;

    sf::Color _statusTextColor;
    float _easingQty = 0.05f, _targetDistance = 0;
    bool _animating = false;
    void doAnimate();

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
    short getNetworkStatus();
    // Cambia el estado de la conexión. (Solo para debug, el estado más adelante se gestionará desde la propia clase)
    void setNetworkStatus(short status);
    // Cambia el texto de estado
    void setStatusText(std::string t);

    void onTick();
    void handleInput(sf::Event &event);
};
