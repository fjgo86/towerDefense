#include "GameStateMainMenu.h"
#include "GameStatePlay.h"

GameStateMainMenu::GameStateMainMenu(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
	this->botonHover = Menu_QTY;

	this->cargaFondo();
	this->createMenu();
}

void GameStateMainMenu::draw(const float dt)
{
	this->game->window.setView(this->view);

	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background, &shader);

	for (int i = 0; i < Menu_QTY; i++) {

		this->game->window.draw(textoOpcionMenu[i]);
	}

	return;
}

void GameStateMainMenu::update(const float dt)
{
	
}

void GameStateMainMenu::cargaFondo()
{
	this->game->background.setTexture(this->game->texmgr.getRef("background"));

	if (sf::Shader::isAvailable())
	{
		if (!shader.loadFromFile("media/shaders/space.frag", sf::Shader::Fragment))
		{
			std::cerr << "ERROR CARGANDO EL SHADER DEL MENU" << std::endl;
		}

		// Cuando llamo a este m�todo setUniform, el programa peta. No lo entiendo
		//shader.setUniform("resolution", sf::Glsl::Vec2(1280.0, 720.0));
	}
}

void GameStateMainMenu::createMenu()
{
	if (!this->fuenteMenu.loadFromFile("media/big_noodle_titling_oblique.ttf"))
	{
		std::cout << "ERROR CARGANDO LA FUENTE DEL MENU" << std::endl;
		this->game->window.close();
	}

	if (!this->bufferSonidoMenu.loadFromFile("media/click.wav"))
	{
		std::cout << "ERROR CARGANDO SONIDO DEL MENU" << std::endl;
		this->game->window.close();
	}

	this->sonidoMenu.setBuffer(this->bufferSonidoMenu);
	this->sonidoMenu.setVolume(10);

	int screenWidth = game->settingsManager.getIntValueOfKey("ScreenWidth", 1280);
	int screenHeight = game->settingsManager.getIntValueOfKey("ScreenHeight", 720);

	for (int i = 0; i < Menu_QTY; i++) {

		this->textoOpcionMenu[i].setFont(fuenteMenu);
		this->textoOpcionMenu[i].setString(StringsMenu[i]);
		this->textoOpcionMenu[i].setCharacterSize((unsigned int)(this->game->settingsManager.getIntValueOfKey("ScreenHeight", 720) * 0.05f));
		this->textoOpcionMenu[i].setPosition((float)screenWidth * 0.1f, (((float)screenHeight * 0.8f) + (float)i * (float)screenHeight * 0.05f));
	}
}

void GameStateMainMenu::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
			case sf::Event::Closed:
			{
				this->game->window.close();
				break;
			}
			
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						this->game->window.close();
						break;

					case sf::Keyboard::L:
						this->enterBuildMode();
						break;
					case sf::Keyboard::T:
						// Esta linea hace que pete el programa
						//shader.setUniform("time", 1.f);
					default:
						break;
				}
			}

			case sf::Event::MouseButtonPressed:
			{
				if (event.mouseButton.button != sf::Mouse::Left || this->botonHover == OpcionesMenu::Menu_QTY)	// No nos importan los clicks con el bot�n derecho.
					break;
				switch (this->botonHover)
				{
					case OpcionesMenu::Menu_Jugar:
						this->enterBuildMode();
						break;

					case OpcionesMenu::Menu_Salir:
						this->game->window.close();
						break;
					default:
						break;
				}
			}

			case sf::Event::MouseMoved:
			{
				sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(this->game->window).x, (float)sf::Mouse::getPosition(this->game->window).y);

				for (int i = 0; i < Menu_QTY; i++) {

					sf::FloatRect textRect = textoOpcionMenu[i].getGlobalBounds();
					textoOpcionMenu[i].setCharacterSize( (unsigned int)(this->game->settingsManager.getIntValueOfKey("ScreenHeight", 720) * 0.05f) );

					if (textRect.contains(mousePos))
					{
						textoOpcionMenu[i].setCharacterSize( (unsigned int)(this->game->settingsManager.getIntValueOfKey("ScreenHeight", 720) * 0.06f) );
						
						if (this->reproducirSonido && this->botonHover != i)
						{
							this->sonidoMenu.play();
						}

						this->botonHover = i;
						return;	// Encontrado bot�n, no necesitamos recorrer m�s c�digo.

					}
				}
				this->botonHover = Menu_QTY;	// No hemos encontrado bot�n, reseteamos el atributo en caso de que haya tenido alg�n otro valor anteriormente.
				break;
			}
			default:
				break;
		}
	}

	return;
}

void GameStateMainMenu::enterBuildMode()
{
	this->game->pushState(new GameStatePlay(this->game));

	return;
}

GameStateMainMenu::~GameStateMainMenu()
{
}
