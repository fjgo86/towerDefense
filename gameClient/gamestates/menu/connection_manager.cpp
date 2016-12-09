#include "connection_manager.h"

#include "../../game.h"

ConnectionManager::ConnectionManager() {

    this->setCenter((float)gGame._screenWidth * -0.5f, (float)gGame._screenHeight / 2.0f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    _networkStatus = Disconnected;

    _fuente.loadFromFile("../gameClient/media/fonts/big_noodle_titling_oblique.ttf");
    
    _statusText.setFont(_fuente);
    _statusText.setString("Texto de Estado");
    _statusText.setOrigin(_statusText.getGlobalBounds().width / 2, _statusText.getGlobalBounds().height / 2);
    _statusText.setPosition(this->getSize().x / 2, this->getSize().y / 2);
}

short ConnectionManager::getNetworkStatus() {

    return _networkStatus;
}

void ConnectionManager::setNetworkStatus(short status) {

    _networkStatus = status;
}

void ConnectionManager::setStatusText(std::string t) {

    _statusText.setString(t);
}

void ConnectionManager::onTick() {

    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(_statusText);
}

void ConnectionManager::handleInput(sf::Event &event) {

}

ConnectionManager::~ConnectionManager() {
}