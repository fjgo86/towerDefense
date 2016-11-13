#pragma once

#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "UI/BotonMenu.h"

#include "../GameState/GameState.h"

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public GameState {
public:
    enum Menu {
        Nueva_Partida,
        Opciones,
        Salir,
        Menu_QTY
    };

    /*
    M�todo para gestionar la musica de fondo. TODO: QUE HAGA MAS COSAS
    action { 0 = stop, 1 = play, 2 = pause }
    */
    void manageBackgroundMusic(short action);
    
    MainMenuManager();
    ~MainMenuManager();

    void onTick();
    void handleInput();

private:
    sf::Font fuente;

    sf::Shader backgroundShader;
    sf::Sprite background, logo;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1, t = 0.f;
    sf::Music backgroundMusic;

    BotonMenu botonesMenu[Menu_QTY];
    std::string Menu_Strings[Menu_QTY] = {
        "Nueva Partida",
        "Opciones",
        "Salir"
    };

    /*
    M�todo para cargar las texturas necesarias
    */
    void loadTextures();
    /*
    M�todo para actualizar elementos antes de dibujarlos
    */
    void update(sf::Event &event);
    /*
    M�todo que carga las texturas, fuentes, botones... y los coloca
    */
    void initMenu();
    /*
    M�todo para iniciar la m�sica de fondo
    */
    void initMusic();
};
