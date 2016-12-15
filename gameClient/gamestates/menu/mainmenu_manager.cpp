#include "mainmenu_manager.h"

#include <logger/logger.h>

#include "../../game.h"

#include "../gameClient/gamestates/menu/state_lobby.h"

MainMenuManager::MainMenuManager() {

    this->setCenter((float)gGame._screenWidth * -1.5f, (float)gGame._screenHeight / 2.0f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    
    if (lobbyState == nullptr) {

        lobbyState = new LobbyState();
        lobbyState = static_cast<LobbyState*>(gGame._statesManager->getEstadoActual());
    }
    

    fuente = gGame._globalFont;

    this->initLobby();
}

void MainMenuManager::initMusic() {

    if (!backgroundMusic.openFromFile("../gameClient/media/music/mainMenu.flac")) {

        _LOG(Log::LOGLVL_ERROR, "Error cargando la musica de fondo.");
    }
        
    backgroundMusic.setVolume(0.5f);
    backgroundMusic.setLoop(true);

    if (backgroundMusic.getStatus() == backgroundMusic.Stopped)
        backgroundMusic.play();
}

void MainMenuManager::initLobby() {

    //this->initMusic();

    sf::Vector2f pos = sf::Vector2f(gGame._screenWidth * 0.05f, gGame._screenHeight * 0.9f);

    for (short i = Menu_QTY - 1; i >= 0; i--) {
            
        // Creamos los botones. NOTA: Se posicionan de abajo a arriba
        // con vistas a añadir algun botón en un futuro.
        botonesMenu[i] = BotonMenu(Menu_Strings[i], fuente);
        botonesMenu[i].setPosition(pos);
        botonesMenu[i].setType(i);
    }
}

void MainMenuManager::handleInput(sf::Event &event) {
    
        switch (event.type) {
            case sf::Event::Closed:
                gGame._gameWindow->close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        gGame._gameWindow->close();
                        break;
                    case sf::Keyboard::Space:        // pulsar SPACE para pasar al juego
                        this->manageBackgroundMusic(0);
                        gGame._statesManager->setEstadoActual("game");
                        break;
                    case sf::Keyboard::N:        // pulsar N para iniciar una nueva partida
                        this->manageBackgroundMusic(0);
                        gGame._statesManager->newGame();
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
					case sf::Mouse::Left:
                        _LOG(Log::LOGLVL_DEBUG, "mouse left at MainMenuManager.\n");
						break;
					default:
						break;
                }
                break;
			default:
				break;
        }

    // Llamada al método para realizar cambios,
    // con una referencia a los eventos por si fuera necesario
    this->update(event);
}

void MainMenuManager::onTick() {

    // Vista con los botones del menu
    gGame._gameWindow->setView((*this));
    // Añadimos todos los botones a ESTA vista (menuView)
    for (int i = 0; i < Menu_QTY; i++) {
        gGame._gameWindow->draw(botonesMenu[i]);
    }
}

void MainMenuManager::update(sf::Event &event) {

    /*
    Actualiza los botones
    */
    for (int i = 0; i < Menu_QTY; i++) {
        botonesMenu[i].update(event, gGame._gameWindow);

        if (botonesMenu[i].getState() == BotonMenu::state::clicked) {

            botonesMenu[i].setState(BotonMenu::state::normal);

            switch (botonesMenu[i].getType()) {
                case Jugar:
                    //this->manageBackgroundMusic(0);
                    //gGame._statesManager->newGame();
                    {
                    //LobbyState* lobbyState = new LobbyState();
                    //lobbyState = static_cast<LobbyState*>(gGame._statesManager->getEstadoActual());
                    if (lobbyState != nullptr) {
                        _DEBUGLOG("funcionaaaa");
                        lobbyState->moveToPlay();
                    }
                    //lobbyState->moveToPlay();
                    }
                break;

                case Opciones:
                    // TODO: Pasar a pantalla de opciones
                    _LOG(Log::LOGLVL_DEBUG, "TODO: Pasar a pantalla de opciones")                         
                    {
                    //LobbyState* lobbyState = new LobbyState();
                    //lobbyState = static_cast<LobbyState*>(gGame._statesManager->getEstadoActual());
                    lobbyState->moveToSettings();
                    }
                break;

                case Desconectar:
                    // TODO: Cerrar la sesión
                    {
                    //LobbyState* lobbyState = new LobbyState();
                    //lobbyState = static_cast<LobbyState*>(gGame._statesManager->getEstadoActual());
                    lobbyState->getConnection()->setNetworkStatus(ConnectionManager::Disconnected);
                    }
                break;
            }
        }
    }
}

/*
Método para gestionar la musica de fondo.
action { 0 = stop, 1 = play, 2 = pause }
*/
void MainMenuManager::manageBackgroundMusic(short action) {

    switch (action) {
        case 0:
            if (backgroundMusic.getStatus() == backgroundMusic.Playing)
                backgroundMusic.stop();
            break;
        case 1:
            if (backgroundMusic.getStatus() == backgroundMusic.Stopped || backgroundMusic.Paused)
                backgroundMusic.play();
            break;
        case 2:
            if (backgroundMusic.getStatus() == backgroundMusic.Playing)
                backgroundMusic.pause();
            break;
        default:
            break;
    }
}

MainMenuManager::~MainMenuManager() {
    backgroundMusic.stop();

    //delete lobbyState;
}