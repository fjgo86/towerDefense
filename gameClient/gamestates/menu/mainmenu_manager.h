#pragma once

#include <functional>

#include <SFML/Audio.hpp>

#include "ViewsWrapper.h"
#include "UI/BotonMenu.h"

#include "../gamestate.h"

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public ViewsWrapper {
public:
    enum Menu : short {
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
    void handleInput(sf::Event &event);

private:
    sf::Font fuente;
    sf::Music backgroundMusic;

    BotonMenu botonesMenu[Menu_QTY];
    std::string Menu_Strings[Menu_QTY] = {
        "Nueva Partida",
        "Opciones",
        "Salir"
    };

    /*
    M�todo para actualizar elementos antes de dibujarlos
    */
    void update(sf::Event &event);
    /*
    M�todo que carga las texturas, fuentes, botones... y los coloca
    */
    void initLobby();
    /*
    M�todo para iniciar la m�sica de fondo
    */
    void initMusic();
};
