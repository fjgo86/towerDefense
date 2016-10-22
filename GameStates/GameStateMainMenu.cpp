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
	this->game->window.draw(this->game->background, &shaderBackground);

	for (int i = 0; i < Menu_QTY; i++) {

		this->game->window.draw(textoOpcionMenu[i]);
	}

	return;
}

void GameStateMainMenu::update(const float dt)
{
	shaderBackground.setUniform("time", shaderBackgroundTime += 0.003);
}

void GameStateMainMenu::cargaFondo()
{
	this->game->background.setTexture(this->game->texmgr.getRef("background"));

	// Comprobamos si la tarjeta grafica soporta shaders
	if (sf::Shader::isAvailable())
	{
		/* SHADER FONDO DE PANTALLA */
		if (!shaderBackground.loadFromFile("media/shaders/space.frag", sf::Shader::Fragment)) // Cargamos el shader desde fichero
			std::cerr << "ERROR CARGANDO EL SHADER DEL FONDO DEL MENU" << std::endl;

		shaderBackground.setUniform("resolution", sf::Glsl::Vec2(this->game->screenWidth, this->game->screenHeight));	// Ajustamos el shader a la resoluci�n de la ventana
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

	for (int i = 0; i < Menu_QTY; i++) {

		this->textoOpcionMenu[i].setFont(fuenteMenu);
		this->textoOpcionMenu[i].setString(StringsMenu[i]);
		this->textoOpcionMenu[i].setCharacterSize((unsigned int)(this->game->screenHeight * 0.05f));
		this->textoOpcionMenu[i].setOutlineThickness(4.f);
		this->textoOpcionMenu[i].setPosition((float)this->game->screenWidth * 0.1f, (((float)this->game->screenHeight * 0.8f) + (float)i * (float)this->game->screenHeight * 0.05f));
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
					textoOpcionMenu[i].setFillColor(sf::Color::White);

					if (textRect.contains(mousePos))
					{
						textoOpcionMenu[i].setFillColor(sf::Color::Yellow);

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
