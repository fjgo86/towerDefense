#include <iostream>
#include <cmath>

#include "state_lobby.h"

#include <logger/logger.h>

#include "../../game.h"
#include "../../network/packets/loginReq.h"

LobbyState::LobbyState() {

    // Inicializamos los ID de las vistas
    loginView.viewId = ViewsWrapper::LoginView;
    connView.viewId = ViewsWrapper::ConnectionView;
    menuView.viewId = ViewsWrapper::MenuView;
    menuPlayView.viewId = ViewsWrapper::MenuPlay;
    menuSettingsView.viewId = ViewsWrapper::MenuSettings;

    _targetDistance = 0;

    // Inicializamos hacia la unica direccion a la que puede ir al iniciar el juego
    moveDir = Left;

    // Inicializamos la vista actual a la del login.
    _vistaActual = &loginView;

    // Inicializamos elementos visuales de la pantalla de login.
    this->initLogin();
}

// Carga las texturas y shaders necesarios.
void LobbyState::loadBackgroundTextures() {

    gGame._textureManager->loadFromFile("logoMenu", "../gameClient/media/logos/logo.png");
    gGame._textureManager->loadFromFile("background", "../gameClient/media/background.jpg");

    if (sf::Shader::isAvailable()) {

        if (!backgroundShader.loadFromFile("../gameClient/media/shaders/clouds.frag", sf::Shader::Fragment)) {

            _LOG(Log::LOGLVL_ERROR, "Error cargando el shader de fondo en el menu principal.\n");
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

    if (_vistaActual->viewId <= ViewsWrapper::MenuView) {

        gGame._gameWindow->draw(logo);
    }

    loginView.onTick();
    connView.onTick();
    menuView.onTick();
    menuPlayView.onTick();
    menuSettingsView.onTick();
    //_vistaActual->onTick();
}

void LobbyState::handleInput() {

    sf::Event event;

    while (gGame._gameWindow->pollEvent(event)) {

        switch (event.type) {

            case sf::Event::Closed:
                gGame._gameWindow->close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::I: // Up
                        loginView.move(0, -50);
                        connView.move(0, -50);
                        menuView.move(0, -50);
                        menuPlayView.move(0, -50);
                        menuSettingsView.move(0, -50);
                        break;
                    case sf::Keyboard::J: // Left
                        loginView.move(50, 0);
                        connView.move(50, 0);
                        menuView.move(50, 0);
                        menuPlayView.move(50, 0);
                        menuSettingsView.move(50, 0);
                        break;
                    case sf::Keyboard::K: // Down
                        loginView.move(0, 50);
                        connView.move(0, 50);
                        menuView.move(0, 50);
                        menuPlayView.move(0, 50);
                        menuSettingsView.move(0, 50);
                        break;
                    case sf::Keyboard::L: // Right
                        loginView.move(-50, 0);
                        connView.move(-50, 0);
                        menuView.move(-50, 0);
                        menuPlayView.move(-50, 0);
                        menuSettingsView.move(-50, 0);
                        break;

                    default:
                        break;
                }
            break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
            
                    case sf::Keyboard::Escape:
                        gGame._gameWindow->close();
                        break;
                    case sf::Keyboard::Return:
                        if ((!loginView.getUser().empty()) && (!loginView.getPassword().empty())) {

                            gGame._client->doConnect();
                            sendData(loginView.getUser(), loginView.getPassword());
                        }
                        break;
                    // Para testear estados de la conexión
                    case sf::Keyboard::F1:
                        //connView.setNetworkStatus(ConnectionManager::Disconnected);
                        moveLobby(&loginView);
                        break;
                    case sf::Keyboard::F2:
                        //connView.setNetworkStatus(ConnectionManager::Connecting);
                        moveLobby(&connView);
                        break;
                    case sf::Keyboard::F3:
                        //connView.setNetworkStatus(ConnectionManager::Connected);
                        moveLobby(&menuView);
                        break;
                    case sf::Keyboard::Up:
                        if (_vistaActual->viewId >= ViewsWrapper::MenuView && _vistaActual->viewId != ViewsWrapper::MenuPlay) {

                            std::cout << "es menuuuu" << std::endl;
                            moveLobby(&menuPlayView);
                        }
                        break;
                    case sf::Keyboard::Down:
                        if (_vistaActual->viewId >= ViewsWrapper::MenuView && _vistaActual->viewId != ViewsWrapper::MenuSettings) {

                            std::cout << "es settings" << std::endl;
                            moveLobby(&menuSettingsView);
                        }
                        break;
                    // Para testear textos de estado
                    case sf::Keyboard::F4:
                        connView.setStatusText("Accediendo al servidor");
                        break;
                    case sf::Keyboard::F5:
                        connView.setStatusText("Conexión exitosa!");
                        break;
                    case sf::Keyboard::F6:
                        connView.setStatusText("Login correcto");
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
                        if ((!loginView.getUser().empty()) && (!loginView.getPassword().empty())) {

                            gGame._client->doConnect();
                            sendData(loginView.getUser(), loginView.getPassword());
                        }
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

void LobbyState::sendData(std::string user, std::string pw) {

    std::cout << "Comprobando en servidor..." << std::endl << "Usuario: " << user << " - Password: " << pw << std::endl;
    PacketLoginReq* packet = new PacketLoginReq(user, pw);
    gGame._client->send(*packet);
    delete packet;
}

void LobbyState::moveLobby(ViewsWrapper* targetView) {

    // TODO: Revisar esto, para poder cambiar entre vistas sin tener que esperar a que termine la animacion
    // Comprueba que no haya una animación en curso
    if (_targetDistance == 0) {

        // Comprueba que no se realice una animación hacia la misma vista.
        if (_vistaActual->viewId != targetView->viewId) _moveLobby = true;

        // Determina si es un movimiento hacia arriba o hacia abajo
        if (targetView->viewId == ViewsWrapper::MenuPlay) {
            moveDir = Up;
        }
        else if (targetView->viewId == ViewsWrapper::MenuSettings) {
            moveDir = Down;
        }
        else if (targetView->viewId > ViewsWrapper::MenuView) {

            moveDir = (_vistaActual->viewId > targetView->viewId) ? Up : Down;
        }
        else if ((targetView->viewId <= ViewsWrapper::MenuView) && (_vistaActual->viewId <= ViewsWrapper::MenuView)) {
            // Determina si es un movimiento hacia la derecha o a la izquierda
            moveDir = (_vistaActual->viewId > targetView->viewId) ? Right : Left;
        }

        std::cout << "vistaActual = " << _vistaActual->viewId << std::endl;

        // Indica cual va a ser la nueva vista
        _vistaActual = targetView;

        std::cout << "targetView = " << _vistaActual->viewId << std::endl;
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
    //switch (connView.getNetworkStatus()) {
    //    case ConnectionManager::Disconnected:
    //        moveLobby(&loginView);
    //        break;
    //    case ConnectionManager::Connecting:
    //        moveLobby(&connView);
    //        break;
    //    case ConnectionManager::Connected:
    //        moveLobby(&menuView);
    //        break;
    //    default:
    //        break;
    //}

    // Mueve la vista
    if (_moveLobby) {

        if (moveDir == Right) {

            _targetDistance = (_vistaActual->getCenter().x - gGame._screenWidth / 2);
        }
        else if (moveDir == Left) {

            _targetDistance = gGame._screenWidth - (_vistaActual->getCenter().x + gGame._screenWidth / 2);
        }
        else if (moveDir == Up) {
            
            _targetDistance = (_vistaActual->getCenter().y - gGame._screenHeight / 2);
        }
        else if (moveDir == Down) {
        
            _targetDistance = gGame._screenHeight - (_vistaActual->getCenter().y + gGame._screenHeight / 2);
        }

        if (_targetDistance > 0.01f && moveDir == Left) {

            loginView.move(_targetDistance * _easingQty, 0);
            connView.move(_targetDistance * _easingQty, 0);
            menuView.move(_targetDistance * _easingQty, 0);
            menuPlayView.move(_targetDistance * _easingQty, 0);
            menuSettingsView.move(_targetDistance * _easingQty, 0);
        }
        else if (_targetDistance > 0.01f && moveDir == Right) {

            loginView.move(-_targetDistance * _easingQty, 0);
            connView.move(-_targetDistance * _easingQty, 0);
            menuView.move(-_targetDistance * _easingQty, 0);
            menuPlayView.move(-_targetDistance * _easingQty, 0);
            menuSettingsView.move(-_targetDistance * _easingQty, 0);
        }
        else if (_targetDistance > 0.01f && moveDir == Up) {

            loginView.move(0, -_targetDistance * _easingQty);
            connView.move(0, -_targetDistance * _easingQty);
            menuView.move(0, -_targetDistance * _easingQty);
            menuPlayView.move(0, -_targetDistance * _easingQty);
            menuSettingsView.move(0, -_targetDistance * _easingQty);
        }
        else if (_targetDistance > 0.01f && moveDir == Down) {

            loginView.move(0, _targetDistance * _easingQty);
            connView.move(0, _targetDistance * _easingQty);
            menuView.move(0, _targetDistance * _easingQty);
            menuPlayView.move(0, _targetDistance * _easingQty);
            menuSettingsView.move(0, _targetDistance * _easingQty);
        }
        else {

            _DEBUGLOG("Animacion Finalizada");
            _targetDistance = 0;
            _moveLobby = false;
        }
    }
}

void LobbyState::moveToPlay() {

    moveLobby(&menuPlayView);
}

void LobbyState::moveToSettings() {

    moveLobby(&menuSettingsView);
}

ConnectionManager* LobbyState::getConnection() {

    return &connView;
}

LobbyState::~LobbyState() {
}
