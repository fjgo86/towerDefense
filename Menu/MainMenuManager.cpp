#include <iostream>

#include "MainMenuManager.h"

#include "../Game.h"

MainMenuManager::MainMenuManager() {

    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");

    this->initMusic();
    this->initMenu();
}

void loadTextures() {

    gGame._textureManager->loadFromFile("logoMenu", "media/logos/logo.png");
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

void MainMenuManager::initMenu() {

    loadTextures();

    // Logo principal del juego
    logo.setTexture(*gGame._textureManager->getRef("logoMenu"));
    logo.setPosition((float)gGame._screenWidth / 2, (float)gGame._screenHeight * 0.2f);
    logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);
    logo.setColor(sf::Color(255, 255, 255, this->alphaLogo));

    /*
    // Texto en la parte baja de la pantalla (PROVISIONAL)
    fuente.loadFromFile("media/fonts/big_noodle_titling_oblique.ttf");
    texto.setFont(fuente);
    texto.setPosition((float)(gGame._screenWidth / 2), (float)(gGame._screenHeight * 0.8f)); // <--- Es correcto usar como Y Width en vez de Height ? NO, era una errata, y no se como estaba funcionando bien asi jaja
    texto.setString("PULSAR ESPACIO PARA CONTINUAR");
    texto.setOrigin(texto.getGlobalBounds().width / 2, texto.getGlobalBounds().height / 2);
    */

    for (int i = 0; i < Menu_QTY; i++) {
        
            botonesMenu[i] = new BotonMenu(
            Menu_Strings[i],
            500,//(gGame._screenWidth * 0.1),
            500,//((gGame._screenHeight * 0.5) + (gGame._screenHeight * 0.1 * i)),
            50.f,
            50.f);     // Coordenadas de origen del boton
        
        /*
        botonMenu[i] = sf::Text(Menu_Strings[i], this->fuente);
        botonMenu[i].setPosition(gGame._screenWidth * 0.05, ((gGame._screenHeight * 0.8) + (botonMenu[i].getGlobalBounds().height * 1.5 * i)));*/
        //std::cout << Menu_Strings[i] << std::endl;
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
                        if (backgroundMusic.getStatus() == backgroundMusic.Playing)
                            backgroundMusic.stop();
                        gGame._statesManager->setEstadoActual("game");
                        break;
                    case sf::Keyboard::N:        // pulsar N para iniciar una nueva partida
                        if (backgroundMusic.getStatus() == backgroundMusic.Playing)
                            backgroundMusic.stop();
                        gGame._statesManager->newGame(true);
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
}

void MainMenuManager::onTick() {

    this->update();

    gGame._gameWindow.draw(logo);
    //gGame._gameWindow.draw(botonMusica);
    //for each(sf::Text boton in botonMenu) {
    for each (BotonMenu* boton in botonesMenu) {
        
        boton->setPosition(500.f, 500.f);
        gGame._gameWindow.draw(*boton);
        std::cout << boton->getText() << std::endl;
    }
    /*
    for (int i = 0; i < Menu_QTY; i++) {

        gGame._gameWindow.draw(*botonesMenu[i]);
        botonesMenu[i]->setPosition(500, 500);
        std::cout << botonesMenu[i]->getText() << std::endl;
    }*/
}

void MainMenuManager::update() {

    if (this->alphaLogo < 255)
        logo.setColor(sf::Color(255, 255, 255, this->alphaLogo++));

    if ((this->scaleLogo += 0.01f) < 1.5f)
        logo.setScale(this->scaleLogo, this->scaleLogo);
}

MainMenuManager::~MainMenuManager() {
    backgroundMusic.stop();
}