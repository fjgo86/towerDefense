#pragma once
#include "../gamestate.h"

#include <SFML\System\Clock.hpp>

#include "colectorbasura.h"
#include "map/map.h"
#include "units/unit_manager.h"

/*
    Clase que se encarga de manejar el tiempo de juego, el flujo de objetos, su interacci�n...
    TODO: Meter aqu� un controlador de teclas, etc
*/
class GameManager : public GameState {
private:
    bool _gameStarted;       ///< bool que indica si hay una partida en curso

    UnitManager* listadoEnemigos;	///< Lista (std::vector) de los enemigos.
    UnitManager* listadoTorres;		///< Lista (std::vector) de las torres.
    ColectorBasura* gbcEnemigos;	///< Recolector de basura para los enemigos.
    ColectorBasura* gbcTorres;		///< Recolector de basura para las torres.
    Map* mapa;                      ///< 
    void addTextoFPS();             ///< Muestra en pantalla los FPS actuales.
    void addTextoMousePos();        ///< Muestra en pantalla la posici�n del rat�n.
    unsigned int    frameCount,     ///< Contador de frames desde el �ltimo segundo.
                    averageFPS;     ///< Frames ejecutados en el �ltimo segundo. //TODO: ahora mismo muestra los frames del �ltimo segundo pero no una ../gameClient/media (average) de los �ltimos segundos.
    float timeCount;                ///< Contador de ticks, ya que el reloj se resetea en cada onTick se lleva aqu� la cuenta de ticks para saber cuando ha pasado un segundo.
    sf::Clock clock;                ///< Reloj del programa.

    void setGameStarted(bool started); ///< Cambia el estado de la propiedad _gameStarted

public:
    
    void onTick();
    void handleInput();

    bool getGameStarted();          ///< Devuelve true si hay una partida en curso

    GameManager();
    ~GameManager();
};

