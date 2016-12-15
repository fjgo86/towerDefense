#pragma once

#include <functional>

#include <SFML/Audio.hpp>

#include "ViewsWrapper.h"
#include "UI/BotonMenu.h"

#include "../gamestate.h"

#include "../gameClient/gamestates/menu/ui/big_button.h"

class LobbyState;

/*
    Clase que se encarga del men� principal de la aplicaci�n
*/
class MainMenuManager : public ViewsWrapper {
public:
    enum Menu : short {
        Jugar,
        Opciones,
        Desconectar,
        Menu_QTY
    };

    /*
    M�todo para gestionar la musica de fondo. TODO: QUE HAGA MAS COSAS
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
        "Jugar",
        "Opciones",
        "Desconectar"
    };

    LobbyState* lobbyState;

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
