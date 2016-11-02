#include "GameManager.h"
#include "Game\Units\Enemigos\Dragon.h"
#include "Game\Units\Torres\Torre1.h"
#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <iostream>


void GameManager::handleInput()
{
	sf::Event event;
	while (gGame.pGameWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				gGame.pGameWindow.close();
				break;
			case sf::Event::KeyReleased:
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						gGame.pGameWindow.close();
						break;
						
					case sf::Keyboard::D:		// pulsar D para crear y posicionar un dragon
					{
						Dragon* dragon = new Dragon();
						//dragon->setPosition((float)sf::Mouse::getPosition(gGame.pGameWindow).x, (float)sf::Mouse::getPosition(gGame.pGameWindow).y);
						dragon->setPosition((float)gGame.iScreenWidth / 2, 0.f);
						dragon->draw(0.0f);
						dragon->setOrigin(true);
						listadoEnemigos->push_back(dragon);
						break;
					}
							
					case sf::Keyboard::T:		// pulsar T para crear y posicionar una torre
					{
						Torre1* torre = new Torre1();
						torre->setPosition((float)sf::Mouse::getPosition(gGame.pGameWindow).x, (float)sf::Mouse::getPosition(gGame.pGameWindow).y);
						torre->draw(0.0f);
						torre->setOrigin(true);
						listadoTorres->push_back(torre);
						break;
					}
						
					default:
						break;
				}
				case sf::Event::MouseButtonPressed:
				{
					switch (event.mouseButton.button)
					{
					case sf::Mouse::Left:
						break;
					}
					break;
				}
				case sf::Event::MouseMoved:
				{
					break;
				}
			}
		}
	}
}

GameManager::GameManager()
{
	frameCount = 0;
	averageFPS = 60;	// lo mismo que window.setFrameLimit();
	listadoEnemigos = new UnitManager();
	listadoTorres = new UnitManager();
	gbcEnemigos = new ColectorBasura();
	gbcTorres = new ColectorBasura();
	
	//listadoEnemigos->push_back(new Dragon());
}


GameManager::~GameManager()
{
	delete listadoEnemigos;
	delete listadoTorres;
	delete gbcEnemigos;
	delete gbcTorres;
}

void GameManager::onTick() {
	float tick = clock.getElapsedTime().asSeconds();
	clock.restart();
	frameCount++;
	timeCount += tick;
	if (timeCount >= 1.0f)
	{
		averageFPS = frameCount;
		frameCount = 0;
		timeCount = 0.0f;
	}
	listadoEnemigos->onTick(gbcEnemigos, tick);
	listadoTorres->onTick(gbcTorres, tick);

	gbcEnemigos->onTick(listadoEnemigos);
	gbcTorres->onTick(listadoTorres);
	addTextoFPS();
	addTextoMousePos();
}

void GameManager::addTextoFPS()
{
	sf::Font font;

	// Carga fichero de fuentes.
	if (!font.loadFromFile("media/fonts/arial.ttf"))
	{
		std::cout << "Error cargando fuente.\n";
	}

	char str[50];
	snprintf(str, sizeof(str), "Frame Count : %d", averageFPS);	// Texto a mostrar en pantalla.
	
	//set up text properties
	sf::Text textFPS;
	textFPS.setFont(font);
	textFPS.setCharacterSize(9);
	textFPS.setStyle(sf::Text::Bold);
	textFPS.setFillColor(sf::Color::White);
	textFPS.setString(str); //ss.str() converts the string buffer into a regular string
	textFPS.setPosition((float)gGame.iScreenWidth - 150.0f, 15.0f);
	
	gGame.pGameWindow.draw(textFPS);
}

void GameManager::addTextoMousePos()
{
	sf::Font font;

	// Carga fichero de fuentes.
	if (!font.loadFromFile("media/fonts/arial.ttf"))
	{
		std::cout << "Error cargando fuente.\n";
	}

	// Guarda en variables la posición actual del ratón relativa a la ventana del juego.
	int fixedX = sf::Mouse::getPosition(gGame.pGameWindow).x,
		fixedY = sf::Mouse::getPosition(gGame.pGameWindow).y;

	// Guarda en variables el tamaño máximo de la ventana del juego.
	int maxSizeX = (int)gGame.pGameWindow.getSize().x,
		maxSizeY = (int)gGame.pGameWindow.getSize().y;
	
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
	snprintf(str, sizeof(str), "MousePos : %d / %d", fixedX, fixedY);	// Texto a mostrar en pantalla, con los valores de la posición del ratón.

	//set up text properties
	sf::Text textCoordsRaton;
	textCoordsRaton.setFont(font);
	textCoordsRaton.setCharacterSize(9);
	textCoordsRaton.setStyle(sf::Text::Bold);
	textCoordsRaton.setFillColor(sf::Color::White);
	textCoordsRaton.setString(str);
	textCoordsRaton.setPosition((float)gGame.iScreenWidth - 150.0f, 35.0f);

	gGame.pGameWindow.draw(textCoordsRaton);
}
