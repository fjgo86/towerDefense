#pragma once

#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "UI/BotonMenu.h"

#include "../GameState/GameState.h"

/*
    Clase que se encarga del menú principal de la aplicación
*/
class MainMenuManager : public GameState {
public:
    enum Menu {
        Nueva_Partida,
        Opciones,
        Salir,
        Menu_QTY
    };

    MainMenuManager();
    ~MainMenuManager();

    void onTick();
    void handleInput();

private:
    sf::Font fuente;

    sf::Sprite logo;
    sf::Uint8 alphaLogo = 0;
    float scaleLogo = 1;
    sf::Music backgroundMusic;

    BotonMenu botonesMenu[Menu_QTY];
    std::string Menu_Strings[Menu_QTY] = {
        "Nueva Partida",
        "Opciones",
        "Salir"
    };

    /*
    Método para cargar las texturas necesarias
    */
    void loadTextures();
    /*
    Método para actualizar elementos antes de dibujarlos
    */
    void update(sf::Event &event);
    /*
    Método que carga las texturas, fuentes, botones... y los coloca
    */
    void initMenu();
    /*
    Método para iniciar la música de fondo
    */
    void initMusic();
    /*
    Método para gestionar la musica de fondo. TODO: QUE HAGA MAS COSAS
    */
    void manageBackgroundMusic();
};
