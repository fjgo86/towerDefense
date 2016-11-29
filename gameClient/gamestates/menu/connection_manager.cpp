#include "connection_manager.h"

#include "../../game.h"

ConnectionManager::ConnectionManager() {

    this->setCenter((float)gGame._screenWidth * -0.5f, (float)gGame._screenHeight / 2.0f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    _networkStatus = Disconnected;

    _fuente.loadFromFile("../gameClient/media/fonts/big_noodle_titling_oblique.ttf");
    
    _statusText.setFont(_fuente);
    _statusText.setString("Conectando al Servidor de Juego");
    _statusText.setOrigin(_statusText.getGlobalBounds().width / 2, _statusText.getGlobalBounds().height / 2);
    _statusText.setPosition(this->getSize().x / 2, this->getSize().y / 2);
}

char ConnectionManager::getNetworkStatus() {

    return (ConnectionManager::NetworkStatus)_networkStatus;
}

void ConnectionManager::setNetworkStatus(char status) {

    _networkStatus = status;
}

void ConnectionManager::onTick() {

    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(_statusText);
}

void ConnectionManager::handleInput(sf::Event &event) {

}

ConnectionManager::~ConnectionManager() {
}