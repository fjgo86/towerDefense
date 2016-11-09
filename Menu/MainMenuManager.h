#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "UI/BotonMenu.h"

#include "../GameState/GameState.h"

enum Menu {
    Nueva_Partida,
    Opciones,
    Salir,
    Menu_QTY
};

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public GameState {
private:
    sf::Font fuente;

    BotonMenu botonesMenu[3];

    sf::Sprite logo, botonMusica;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1;
    sf::Music backgroundMusic;

    std::string Menu_Strings[3] = {
        "Nueva Partida",
        "Opciones",
        "Salir"
    };

    /*
    M�todo para actualizar elementos antes de dibujarlos
    */
    void update();
    /*
    M�todo que carga las texturas, fuentes, botones... y los coloca
    */
    void initMenu();
    /*
    M�todo para iniciar la m�sica de fondo
    */
    void initMusic();

public:
    MainMenuManager();
    ~MainMenuManager();

    void onTick();
    void handleInput();
};

