#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameManager.h"
#include "GameStatesManager.h"
#include <iostream>


void Game::onTick()
{
	pGameManager->handleInput();
    pGameManager->onTick();
}

Game::Game()
{
	std::cout << "Inicializando Game" << std::endl;
	iScreenWidth = 1280;
	iScreenHeight = 720;
    pGameWindow.create(sf::VideoMode(this->iScreenWidth, this->iScreenHeight), "Tower Defense");
    pGameWindow.setFramerateLimit(60);
    pGameWindow.clear();

	pTextureManager = new TextureManager();
    pGameManager = new GameManager();

	//pGameStatesManager = new GameStatesManager();
	//pGameManager = pGameStatesManager->getEstadoActual();
}


Game::~Game()
{
    delete pTextureManager;
    delete pGameManager;
}
