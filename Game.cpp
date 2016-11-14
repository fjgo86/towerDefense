#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "Menu/MainMenuManager.h"
#include "Game/GameManager.h"
#include "GameState/GameStatesManager.h"



void Game::onTick() {
	_statesManager->getEstadoActual()->handleInput();
	_statesManager->getEstadoActual()->onTick();
}

Game::Game() {
    std::cout << "Inicializando Game" << std::endl;
    _screenWidth = 1280;
    _screenHeight = 720;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    _gameWindow.create(sf::VideoMode(this->_screenWidth, this->_screenHeight), "Tower Defense", sf::Style::Default, settings);
	_gameWindow.setFramerateLimit(60);
	_gameWindow.clear();

    _textureManager = new TextureManager();
	_spriteManager = new SpriteManager(_textureManager);

    _statesManager = new GameStatesManager();
    _statesManager->initEstados();
	_statesManager->setEstadoActual("menu");
}

Game::~Game(){
    delete _textureManager;
	delete _statesManager;
}