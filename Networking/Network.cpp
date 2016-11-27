#include "Network.h"
#include <iostream>

enum PacketList {
    PACKET_Login = 1
};

Network::Network() {
    _targIP = "127.0.0.1";
    status = socket.connect(_targIP, 53000);
    if (status != sf::Socket::Done) {
        std::cout << "Conexion sin establecer" << std::endl;
    }
    else {
        std::cout << "Conexion establecida" << std::endl;
    }
    sf::Packet packet;
    packet << PACKET_Login << "Hola" << "qtal";
    socket.send(packet);
}

Network::~Network() {
}