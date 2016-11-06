#pragma once
#include <map>

#include "GameState.h"

class GameStatesManager {   
private:
    std::map<std::string, GameState*> estados;
    GameState* estadoActual;

public:

    /*
    M�todo que se ejecuta solo la primera vez, para a�adir los estados esenciales (menu, partida...)
    */
    void initEstados();
    /*
    Obtener el estado actual
    */
    GameState* getEstadoActual();
    /*
    Cambiar el estado actual
    */
    void setEstadoActual(std::string estado);
    /*
    Crear una partida nueva
    */
    void GameStatesManager::newGame(bool iniciarAutomaticamente = false);
    
    GameStatesManager();
    ~GameStatesManager();
};