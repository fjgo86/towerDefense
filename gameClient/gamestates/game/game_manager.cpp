#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "game_manager.h"
#include "../../game.h"
#include "units/enemigos/dragon.h"
#include "units/torres/torre1.h"

void GameManager::handleInput() {

    sf::Event event;

    while (gGame._gameWindow->pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                gGame._gameWindow->close();
                break;
            case sf::Event::KeyReleased: {
                switch (event.key.code){
                    case sf::Keyboard::Escape:
                        gGame._statesManager->setEstadoActual("menu");
                        break;
                        
                    case sf::Keyboard::D:{        // pulsar D para crear y posicionar un dragon
                        Dragon* dragon = new Dragon();
                        //dragon->setPosition((float)sf::Mouse::getPosition(gGame.pGameWindow).x, (float)sf::Mouse::getPosition(gGame.pGameWindow).y);
                        dragon->setPosition((float)gGame._screenWidth / 2, 0.f);
                        dragon->draw(0.0f);
                        dragon->setOrigin(true);
                        listadoEnemigos->push_back(dragon);
                        break;
                    }
                            
                    case sf::Keyboard::T: {        // pulsar T para crear y posicionar una torre
                        Torre1* torre = new Torre1();
                        torre->setPosition((float)sf::Mouse::getPosition(*gGame._gameWindow).x, (float)sf::Mouse::getPosition(*gGame._gameWindow).y);
                        torre->draw(0.0f);
                        torre->setOrigin(true);
                        listadoTorres->push_back(torre);
                        break;
                    }
                        
                    default:
                        break;
                }
                case sf::Event::MouseButtonPressed: {
                    switch (event.mouseButton.button) {
                    case sf::Mouse::Left:
                        break;
                    }
                    break;
                }
                case sf::Event::MouseMoved: {
                    break;
                }
            }
        }
    }
}

GameManager::GameManager() {
    frameCount = 0;
    averageFPS = 60;    // lo mismo que window.setFrameLimit();
    listadoEnemigos = new UnitManager();
    listadoTorres = new UnitManager();
    gbcEnemigos = new ColectorBasura();
    gbcTorres = new ColectorBasura();
    mapa = new Map();
    
    setGameStarted(true);
}


GameManager::~GameManager() {
    delete listadoEnemigos;
    delete listadoTorres;
    delete gbcEnemigos;
    delete gbcTorres;

    setGameStarted(false);
}

void GameManager::onTick() {
    float tick = clock.getElapsedTime().asSeconds();
    clock.restart();
    frameCount++;
    timeCount += tick;
    if (timeCount >= 1.0f){
        averageFPS = frameCount;
        frameCount = 0;
        timeCount = 0.0f;
    }
    mapa->draw();
    listadoEnemigos->onTick(gbcEnemigos, tick);
    listadoTorres->onTick(gbcTorres, tick);

    gbcEnemigos->onTick(listadoEnemigos);
    gbcTorres->onTick(listadoTorres);
    addTextoFPS();
    addTextoMousePos();
}

void GameManager::addTextoFPS() {
    sf::Font font;

    // Carga fichero de fuentes.
    if (!font.loadFromFile("media/fonts/arial.ttf")) {
        std::cout << "Error cargando fuente.\n";
    }

    char str[50];
    snprintf(str, sizeof(str), "Frame Count : %d", averageFPS);    // Texto a mostrar en pantalla.
    
    //set up text properties
    sf::Text textFPS;
    textFPS.setFont(font);
    textFPS.setCharacterSize(9);
    textFPS.setStyle(sf::Text::Bold);
    textFPS.setFillColor(sf::Color::White);
    textFPS.setString(str); //ss.str() converts the string buffer into a regular string
    textFPS.setPosition((float)gGame._screenWidth - 150.0f, 15.0f);
    
    gGame._gameWindow->draw(textFPS);
}

void GameManager::addTextoMousePos() {
    sf::Font font;

    // Carga fichero de fuentes.
    if (!font.loadFromFile("media/fonts/arial.ttf")){
        std::cout << "Error cargando fuente.\n";
    }

    // Guarda en variables la posición actual del ratón relativa a la ventana del juego.
    int fixedX = sf::Mouse::getPosition(*gGame._gameWindow).x,
        fixedY = sf::Mouse::getPosition(*gGame._gameWindow).y;

    // Guarda en variables el tamaño máximo de la ventana del juego.
    int maxSizeX = (int)gGame._gameWindow->getSize().x,
        maxSizeY = (int)gGame._gameWindow->getSize().y;
    
    // Comprobación para que, aunque el ratón esté fuera de la pantalla, el juego no use coordenadas que no están dentro suya.
    if (fixedX > maxSizeX) {
        fixedX = maxSizeX;
    }
    else if (fixedX < 0) {
        fixedX = 0;
    }
    
    if (fixedY > maxSizeY) {
        fixedY = maxSizeY;
    }
    else if (fixedY < 0) {
        fixedY = 0;
    }
    // Fin comprobación


    char str[50]; // Storage para el texto a mostrar en pantalla
    snprintf(str, sizeof(str), "MousePos : %d / %d", fixedX, fixedY);    // Texto a mostrar en pantalla, con los valores de la posición del ratón.

    //set up text properties
    sf::Text textCoordsRaton;
    textCoordsRaton.setFont(font);
    textCoordsRaton.setCharacterSize(9);
    textCoordsRaton.setStyle(sf::Text::Bold);
    textCoordsRaton.setFillColor(sf::Color::White);
    textCoordsRaton.setString(str);
    textCoordsRaton.setPosition((float)gGame._screenWidth - 150.0f, 35.0f);

    gGame._gameWindow->draw(textCoordsRaton);
}

bool GameManager::getGameStarted() {

    return _gameStarted;
}

void GameManager::setGameStarted(bool started) {

    _gameStarted = started;
}