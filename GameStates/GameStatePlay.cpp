#include <iostream>
#include "GameStateMainMenu.h"
#include "GameStatePlay.h"
#include "../Game.h"
#include "../GameObjects/ObjectManager.h"
#include "../GameObjects/Torre.h"
#include "../GameAnimations/MouseCursor.h"

GameStatePlay::GameStatePlay(Game* game)
{
	this->game = game;
	this->actionState = ActionState::NONE;

	this->game->texmgr.loadTexture("background-building", "media/background_building.jpg");
	this->game->backgroundBuilding.setTexture(this->game->texmgr.getRef("background-building"));
	objMouseOver = NULL;

	// Inicializaci�n del circulo que indica el rango de la torre
	//this->rangeCircle.setRadius(100.f);
	this->rangeCircle.setFillColor(sf::Color(200, 0, 0, 50));
	this->rangeCircle.setOutlineColor(sf::Color(200, 0, 0));
	this->rangeCircle.setOutlineThickness(1);
	//this->rangeCircle.setOrigin(this->rangeCircle.getGlobalBounds().height / 2, this->rangeCircle.getGlobalBounds().width / 2);

	// Aqui cargamos en el textureManager el spriteSheet con todos los frames de la animacion
	this->game->texmgr.loadTexture("prueba-anim", "media/prueba.png");

	// Aqui asignamos el spriteSheet a la animaci�n, para posteriormente indicarle cuales son los frames que vamos a utilizar
	animacionTorreta.setSpriteSheet(this->game->texmgr.getRef("prueba-anim"));

	// Aqui vamos recorriendo el spriteSheet (en este caso son 5 frames) y vamos diciendole en rectangulos la posicion y tama�o de cada uno de los frames
	for (int i = 0; i < 5; i++) 
		animacionTorreta.addFrame(sf::IntRect(i * 69, 0, 69, 69));
	
	// Aqui indicamos el tiempo que tiene que durar la animacion, algo sobre el pause que no se muy bien que es, y si queremos que haga loop
	animatedSprite = AnimatedSprite(sf::seconds(0.2f), true, false);
	// En este momento creo que se trata como si se tratara de un sf::Sprite
	animatedSprite.setPosition(sf::Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
}

void GameStatePlay::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->backgroundBuilding);
	gObjManager.draw(game);
	if (placingObject)
	{
		game->window.setMouseCursorVisible(false);	//al regenerar la pantalla se asigna de nuevo a true de manera autom�tica, no es necesario deshacer esta linea.
		sf::Texture texture;
		if (!texture.loadFromFile(placingObject->getIconSrc()))
			return;
		game->window.draw(placingObject->getSprite());
	}
	else if (objMouseOver && objMouseOver->getRange() > 0.f)
	{
		// TODO: El rango se obtendr� mediante la torre, dependiendo su tipo
		this->rangeCircle.setRadius(objMouseOver->getRange());
		this->rangeCircle.setPosition((float)objMouseOver->p.x, (float)objMouseOver->p.y);
		this->rangeCircle.setOrigin(this->rangeCircle.getGlobalBounds().height / 2, this->rangeCircle.getGlobalBounds().width / 2);
		game->window.draw(this->rangeCircle);
	}

	// Aqui se dibuja como si fuera un sf::Sprite normal y corriente
	game->window.draw(animatedSprite);
}

void GameStatePlay::update(const float dt)
{
	sf::Time frameTime = frameClock.restart();
	// Esto creo que es para que se vaya cambiando el frame de la animacion
	animatedSprite.update(frameTime);
	gObjManager.onTick(dt);
}

void GameStatePlay::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:

						if (placingObject)
						{
							delete placingObject;
							placingObject = nullptr;
							this->actionState = ActionState::NONE;
							break;
						}
						//this->game->window.close();
						this->leaveBuildMode();
						break;

					case sf::Keyboard::Y:
						std::cout << "ActionState = NONE" << std::endl;
						this->actionState = ActionState::NONE;
						break;

					case sf::Keyboard::U:
						std::cout << "ActionState = HUMAN" << std::endl;
						this->actionState = ActionState::HUMAN;
						break;

					case sf::Keyboard::I:
						std::cout << "ActionState = FIRE" << std::endl;
						this->actionState = ActionState::FIRE;
						break;

					case sf::Keyboard::O:
						std::cout << "ActionState = WATER" << std::endl;
						this->actionState = ActionState::WATER;
						break;

					case sf::Keyboard::H:
						std::cout << "ActionState = CREAR TORRE" << std::endl;
						this->actionState = ActionState::BUILDING;
						placingObject = new Torre();
						placingObject->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y);
						break;
				}
				break;
			case sf::Event::MouseButtonPressed:
			{
				switch (event.mouseButton.button)
				{
					case sf::Mouse::Left:
						std::cout << "Action = Pulsa boton Izquierdo" << std::endl;
						if (this->actionState == ActionState::BUILDING)
						{
							if (gObjManager.findObjectAt(sf::Mouse::getPosition(game->window)))	// Si no se puede mover a esa posicion por que est� obstruida abortamos el click.
								break;
							Torre* torre = (Torre*)placingObject;
							this->actionState = ActionState::NONE;
							torre->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y);
							game->window.draw(torre->getSprite());
							placingObject = nullptr;
							gObjManager.add(torre);
							std::cout << "Action = Emplaza torre en " << torre->getSprite().getPosition().x << "/" << torre->getSprite().getPosition().y << std::endl;

							// Este m�todo se llama en el momento que quieras que se inicie la animaci�n
							std::cout << "Iniciando Animaci�n de torreta" << std::endl;
							animatedSprite.play(animacionTorreta);
							// Esta llamada a setLooped creo que es redundante, puesto que ya indicamos en su constructor: false
							animatedSprite.setLooped(false);
						}
						else
						{
							if (objMouseOver)
								std::cout << "Click en torre con UID 0x" << objMouseOver->getUID().toInt() << std::endl;
						}
						break;
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				objMouseOver = gObjManager.findObjectAt(sf::Mouse::getPosition(game->window));
				if (placingObject)
				{
					placingObject->placeAt(sf::Mouse::getPosition(this->game->window).x, sf::Mouse::getPosition(this->game->window).y, objMouseOver ? false : true);
					break;
				}
				if (objMouseOver)
				{
					MouseCursor Cursor(MouseCursor::HAND);
					Cursor.set(game->window.getSystemHandle());
				}
				else
				{
					MouseCursor Cursor(MouseCursor::NORMAL);
					Cursor.set(game->window.getSystemHandle());
				}
			}
		}
	}
}

void GameStatePlay::leaveBuildMode()
{
	this->game->pushState(new GameStateMainMenu(this->game));

	return;
}

GameStatePlay::~GameStatePlay()
{
}
