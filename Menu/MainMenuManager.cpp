#include <iostream>

#include "MainMenuManager.h"

#include "../Game.h"

MainMenuManager::MainMenuManager() {

    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");

    viewBackground = sf::View(sf::Vector2f(gGame._screenWidth / 2, gGame._screenHeight / 2),
      sf::Vector2f(gGame._screenWidth, gGame._screenHeight));

    viewLobby = sf::View(sf::Vector2f(gGame._screenWidth * 1.5, gGame._screenHeight / 2),
        sf::Vector2f(gGame._screenWidth, gGame._screenHeight));
    
    this->initLobby();
}

void MainMenuManager::loadTextures() {

    gGame._textureManager->loadFromFile("logoMenu", "media/logos/logo.png");
    gGame._textureManager->loadFromFile("background", "media/background.jpg");

    if (sf::Shader::isAvailable()) {

        if (!backgroundShader.loadFromFile("media/shaders/clouds.frag", sf::Shader::Fragment)) {

            std::cout << "Error cargando el shader de fondo en el menu principal." << std::endl;
        }
        else {

            backgroundShader.setUniform("resolution", sf::Glsl::Vec2(gGame._screenWidth, gGame._screenHeight));
            background.setTexture(*gGame._textureManager->getRef("background"));
        }
    }
}

void MainMenuManager::initMusic() {

    if (!backgroundMusic.openFromFile("media/music/mainMenu.flac"))
        std::cout << "Error cargando la musica de fondo." << std::endl;
    backgroundMusic.setVolume(0.5f);
    backgroundMusic.setLoop(true);

    if (backgroundMusic.getStatus() == backgroundMusic.Stopped)
        backgroundMusic.play();
    //std::cout << "Reproduciendo musica" << std::endl;
}

void MainMenuManager::initLobby() {

    this->loadTextures();
    this->initMusic();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));

    sf::Vector2f pos = sf::Vector2f(viewLobby.getViewport().width * 0.05f, viewLobby.getViewport().height * 0.9f);

    for (int i = Menu_QTY - 1; i >= 0; i--) {
            
            // Creamos los botones, obtenemos el tamaño del texto
            // una vez creados, y los posicionamos en relacion a esto
            botonesMenu[i] = BotonMenu(Menu_Strings[i], fuente);
            botonesMenu[i].setPosition(pos);
            botonesMenu[i].setType(i);
    }
}

void MainMenuManager::handleInput() {
    sf::Event event;
    while (gGame._gameWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                gGame._gameWindow.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        gGame._gameWindow.close();
                        break;
                    case sf::Keyboard::Space:        // pulsar SPACE para pasar al juego
                        this->manageBackgroundMusic(0);
                        gGame._statesManager->setEstadoActual("game");
                        break;
                    case sf::Keyboard::N:        // pulsar N para iniciar una nueva partida
                        this->manageBackgroundMusic(0);
                        gGame._statesManager->newGame();
                        break;
                    case sf::Keyboard::Return:
                        moveLobby();
                        break;
                    default:
                        break;
                }
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
					case sf::Mouse::Left:
						break;
					default:
						break;
                }
                break;
            case sf::Event::MouseMoved: 
                break;
			default:
				break;
        }
    }

    // Llamada al método para realizar cambios,
    // con una referencia a los eventos por si fuera necesario
    this->update(event);
}

void MainMenuManager::moveLobby() {

    std::cout << "button pos x: " << botonesMenu[0].getPosition().x << std::endl;
    std::cout << "button pos y: " << botonesMenu[0].getPosition().y << std::endl;
    //viewLobby.move(1, 0);
    //viewLobby.setCenter(gGame._screenWidth / 2, gGame._screenHeight / 2);
}

void MainMenuManager::onTick() {

    // Vista con el fondo y el logo
    gGame._gameWindow.setView(viewBackground);
    gGame._gameWindow.draw(background, &backgroundShader);
    gGame._gameWindow.draw(logo);

    // Vista con los botones del menu
    gGame._gameWindow.setView(viewLobby);
    for (int i = 0; i < Menu_QTY; i++) {
        gGame._gameWindow.draw(botonesMenu[i]);
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
                case Nueva_Partida:
                    this->manageBackgroundMusic(0);
                    gGame._statesManager->newGame();
                    break;
                case Opciones:
                    std::cout << "TODO: Pasar a pantalla de opciones" << std::endl;
                    break;
                case Salir:
                    gGame._gameWindow.close();
                    break;
                default:
                    break;
            }
        }
    }

    // Este parametro controla la velocidad de movimiento de las nubes
    backgroundShader.setUniform("time", t += 0.5f);

    if (viewLobby.getCenter().x > (gGame._screenWidth / 2)) {

        //std::cout << "ejecutando if - view.x = " << viewLobby.getCenter().x << std::endl;
        //viewLobby.move(-5, 0);
    }

    /*
    Transformaciones visuales en el logo
    */
    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01f) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);
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
}