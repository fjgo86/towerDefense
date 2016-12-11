#pragma once

#include <functional>

#include <SFML/Audio.hpp>

#include "ViewsWrapper.h"
#include "UI/BotonMenu.h"

#include "../gamestate.h"

/*
    Clase que se encarga del menú principal de la aplicación
*/
class MainMenuManager : public ViewsWrapper {
public:
    enum Menu : short {
        Nueva_Partida,
        Opciones,
        Desconectar,
        Menu_QTY
    };

    /*
    Método para gestionar la musica de fondo. TODO: QUE HAGA MAS COSAS
    action { 0 = stop, 1 = play, 2 = pause }
    */
    void manageBackgroundMusic(short action);
    
    MainMenuManager();
    ~MainMenuManager();

    // onTick del menu principal
    void onTick();
    // handleInput del menu principal
    void handleInput(sf::Event &event);

private:
    // Fuente de los textos del menu principal
    sf::Font fuente;
    // Musica de fondo en el menu principal
    sf::Music backgroundMusic;

    // Array con los botones del menu principal
    BotonMenu botonesMenu[Menu_QTY];
    // Textos de los botones del menu principal
    std::string Menu_Strings[Menu_QTY] = {
        "Nueva Partida",
        "Opciones",
        "Salir"
    };

    /*
    Método para actualizar elementos antes de dibujarlos
    */
    void update(sf::Event &event);
    /*
    Método que carga las texturas, fuentes, botones... y los coloca
    */
    void initLobby();
    /*
    Método para iniciar la música de fondo
    */
    void initMusic();
};
