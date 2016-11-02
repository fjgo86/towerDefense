#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameManager.h"
#include "GameStatesManager.h"
#include <iostream>


void Game::onTick(){
	pGameManager->handleInput();
    pGameManager->onTick();
}

Game::Game(){
	std::cout << "Inicializando Game" << std::endl;
	iScreenWidth = 1280;
	iScreenHeight = 720;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

    pGameWindow.create(sf::VideoMode(this->iScreenWidth, this->iScreenHeight), "Tower Defense", sf::Style::Default, settings);
    pGameWindow.setFramerateLimit(60);
    pGameWindow.clear();

	pTextureManager = new TextureManager();
    pGameManager = new GameManager();

	pGameStatesManager = new GameStatesManager();
	pGameStatesManager->setEstadoActual(pGameManager);
}


Game::~Game(){
    delete pTextureManager;
    delete pGameManager;
}
