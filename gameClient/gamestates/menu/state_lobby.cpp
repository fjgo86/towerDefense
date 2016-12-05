#include <iostream>
#include <cmath>

#include "state_lobby.h"

#include "../../game.h"
#include "../../network/packets/login.h"

LobbyState::LobbyState() {

    // Inicializamos los ID de las vistas
    loginView.viewId = ViewsWrapper::LoginView;
    connView.viewId = ViewsWrapper::ConnectionView;
    menuView.viewId = ViewsWrapper::MenuView;

    // Iniciamos la vista actual a la del login.
    _vistaActual = &loginView;

    // Iniciamos elementos visuales de la pantalla de login.
    this->initLogin();
}

// Carga las texturas y shaders necesarios.
void LobbyState::loadBackgroundTextures() {

    gGame._textureManager->loadFromFile("logoMenu", "../gameClient/media/logos/logo.png");
    gGame._textureManager->loadFromFile("background", "../gameClient/media/background.jpg");

    if (sf::Shader::isAvailable()) {

        if (!backgroundShader.loadFromFile("../gameClient/media/shaders/clouds.frag", sf::Shader::Fragment)) {

            std::cout << "Error cargando el shader de fondo en el menu principal." << std::endl;
        }
        else {

            backgroundShader.setUniform("resolution", sf::Glsl::Vec2((float)gGame._screenWidth, (float)gGame._screenHeight));
            background.setTexture(*gGame._textureManager->getRef("background"));
        }
    }
}

// Posicionamiento de los elementos en el fondo de pantalla
void LobbyState::initLogin() {

    // Carga de texturas
    this->loadBackgroundTextures();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));
}

void LobbyState::onTick() {

    // Recupera la vista por defecto (la de esta clase) y "incrusta" los elementos en ella
    gGame._gameWindow->setView(gGame._gameWindow->getDefaultView());
    gGame._gameWindow->draw(background, &backgroundShader);
    gGame._gameWindow->draw(logo);

    loginView.onTick();
    connView.onTick();
    menuView.onTick();
    //_vistaActual->onTick();
}

void LobbyState::handleInput() {

    sf::Event event;

    while (gGame._gameWindow->pollEvent(event)) {

        switch (event.type) {

            case sf::Event::Closed:
                gGame._gameWindow->close();
                break;
               
            case sf::Event::KeyReleased:
                switch (event.key.code) {
            
                    case sf::Keyboard::Escape:
                        gGame._gameWindow->close();
                        break;
                    case sf::Keyboard::Return:
                        //sendData(loginView.getUser(), loginView.getPassword());
                        break;
                    case sf::Keyboard::Left:
                        loginView.move(50, 0);
                        connView.move(50, 0);
                        menuView.move(50, 0);
                        break;
                    case sf::Keyboard::Right:
                        loginView.move(-50, 0);
                        connView.move(-50, 0);
                        menuView.move(-50, 0);
                        break;
                    case sf::Keyboard::F1:
                        connView.setNetworkStatus(ConnectionManager::Disconnected);
                        break;
                    case sf::Keyboard::F2:
                        connView.setNetworkStatus(ConnectionManager::Connecting);
                        break;
                    case sf::Keyboard::F3:
                        connView.setNetworkStatus(ConnectionManager::Connected);
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    _mousePos = sf::Mouse::getPosition(*gGame._gameWindow);
                    if (loginView.getConnectButton().getGlobalBounds().contains((sf::Vector2f)_mousePos)) {
                        gGame._client->connect();
                        sendData(loginView.getUser(), loginView.getPassword());
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
        }

        _vistaActual->handleInput(event);
    }

    // Llamada al método para realizar cambios,
    // con una referencia a los eventos por si fuera necesario
    this->update();
}

void LobbyState::sendData(std::string u, std::string p) {

    std::cout << "Comprobando en servidor..." << std::endl << "Usuario: " << u << " - Password: " << p << std::endl;
    PacketLogin* packet = new PacketLogin();
    packet->checkAccount(u, p);
    gGame._client->send(*packet);
    delete packet;
}

void LobbyState::moveLobby(ViewsWrapper* targetView) {

    // Comprueba que no haya una animación en curso
    if (_targetDistance == 0) {

        // Comprueba que no se realice una animación hacia la misma vista.
        if (_vistaActual->viewId != targetView->viewId) _moveLobby = true;
        // Determina si es un movimiento hacia la derecha o a la izquierda
        _moveLobbyToRight = (_vistaActual->viewId > targetView->viewId) ? true : false;
        // Indica cual va a ser la nueva vista
        _vistaActual = targetView;
    }
}

void LobbyState::update() {

    // Este parametro controla la velocidad de movimiento de las nubes
    backgroundShader.setUniform("time", _backgroundUniform += 0.5f);

    /*
    Transformaciones visuales en el logo
    */
    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01f) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);

    // Coloca la vista dependiendo del estado de la conexión.
    // De esta manera, el movimiento entre vistas se realiza automáticamente
    switch (connView.getNetworkStatus()) {
        case ConnectionManager::Disconnected:
            moveLobby(&loginView);
            break;
        case ConnectionManager::Connecting:
            moveLobby(&connView);
            break;
        case ConnectionManager::Connected:
            moveLobby(&menuView);
            break;
        default:
            break;
    }

    // Mueve la vista
    if (_moveLobby) {

        if (_moveLobbyToRight) {

            _targetDistance = (_vistaActual->getCenter().x - gGame._screenWidth / 2);
        }
        else {

            _targetDistance = gGame._screenWidth - (_vistaActual->getCenter().x + gGame._screenWidth / 2);
        }

        if (_targetDistance > 0.01f && !_moveLobbyToRight) {
            loginView.move(_targetDistance * _easingQty, 0);
            connView.move(_targetDistance * _easingQty, 0);
            menuView.move(_targetDistance * _easingQty, 0);
        }
        else if (_targetDistance > 0.01f && _moveLobbyToRight) {

            loginView.move(-_targetDistance * _easingQty, 0);
            connView.move(-_targetDistance * _easingQty, 0);
            menuView.move(-_targetDistance * _easingQty, 0);
        }
        else {

            std::cout << "Animacion Finalizada" << std::endl;
            _targetDistance = 0;
            _moveLobby = false;
        }
    }
}

LobbyState::~LobbyState() {
}
