#pragma once
#include <map>

#include "GameState.h"

class GameStatesManager {   
private:
    std::map<std::string, GameState*> estados;
    GameState* estadoActual;
	bool _gameStarted;

public:

    /*
    Método que se ejecuta solo la primera vez, para añadir los estados esenciales (menu, partida...)
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
    void newGame(bool iniciarAutomaticamente = true);
	/*
	Finaliza la partida existente
	*/
	void endGame();
    /*
	Comprobar si hay una partida existente
	*/
	bool isGameStarted();

    GameStatesManager();
    ~GameStatesManager();
};