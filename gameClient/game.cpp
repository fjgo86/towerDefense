#include <iostream>
#include <logger/log_manager.h>
#include "game.h"

#include <SFML/Window/VideoMode.hpp>

#include "gamestates/menu/mainmenu_manager.h"
#include "gamestates/game/game_manager.h"
#include "gamestates/gamestates_manager.h"

LogManager gLog;

void Game::onTick() {
    _statesManager->getEstadoActual()->handleInput();
    _statesManager->getEstadoActual()->onTick();
    _client->onTick();
    gLog.onTick();
}

Game::Game() {
}

Game::~Game(){
    delete _textureManager;
    delete _spriteManager;
	delete _statesManager;
    delete _gameWindow;
    delete _client;
}

void Game::init() {
    std::cout << "Inicializando Game" << std::endl;
    _screenWidth = 1280;
    _screenHeight = 720;

    _globalFont.loadFromFile("../gameClient/media/fonts/big_noodle_titling_oblique.ttf");

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    _gameWindow = new sf::RenderWindow(sf::VideoMode(this->_screenWidth, this->_screenHeight), "Tower Defense", sf::Style::Default, settings);
    _gameWindow->setFramerateLimit(60);
    _gameWindow->clear();

    _textureManager = new TextureManager();
    _spriteManager = new SpriteManager(_textureManager);

    _statesManager = new GameStatesManager();
    _statesManager->initEstados();
    _statesManager->setEstadoActual("lobby");

    _client = new Client();
}