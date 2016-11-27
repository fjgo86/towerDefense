#pragma once
#include <SFML/Network.hpp>

class Network {
    sf::IpAddress _targIP;
    sf::TcpSocket socket;
    sf::Socket::Status status;
public:
    Network();
    ~Network();
};