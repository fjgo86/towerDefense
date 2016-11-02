#pragma once
#include "SFML/Graphics.hpp"

enum eDir {
    DIR_S,
    DIR_SW,
    DIR_W,
    DIR_NW,
    DIR_E,
    DIR_SE,
    DIR_N,
    DIR_NE
};

class AnimatedSprite
{
private:
	sf::Texture sfTexture;					///< Textura del objeto.
	sf::Sprite sfSprite;					///< Sprite del objeto.
	int sizeX;								///< Tamaño X de cada frame.
	int sizeY;								///< Tamaño Y de cada frame.
	sf::Clock clock;						///< Reloj del juego.
	int frameList[4] = { 0, 1, 2, 1};		///< La animación completa se compone de un ciclo entero de las animaciones: inicio - final - inicio.
	int frameActual = 0;					///< Contador de frames.
	int direccion = 0;						///< Direccion 0-8: 0 = SUR, 1 = OESTE, 2 = ESTE, 3 = NORTE.
	float lastTick = 0.0f;					///< Ticks desde la última vez que se actualizó la animación.


    bool _isStopped;            ///< True = no se mueve, false = se mueve normalmente.
    eDir _dir;                  ///< Dirección en la que se moverá.
public:
    float _speed;               ///< Cuantos pixeles se mueve por cada tick de la unidad.
	AnimatedSprite(std::string nombre, const char * rutaImagen);
	AnimatedSprite();
	~AnimatedSprite();
	void draw();							///< Dibuja el objeto en pantalla.
	void update(const float elapsed);		///< Actualiza la animación del objeto.

	// SETTERS
    /*
    Cambia la posición del objeto
    */
	void setPosition(float x, float y);
    /*
    Método que mueve el origen de la esquina top-left al center del sprite
    */
	void setOrigin(bool centered = true);
    /*
    Método sobrecargado para mover el origen a las coordenadas especificadas
    */
	void setOrigin(float x, float y);
    /*
    Método para cambiar la dirección.
    */
	void setDireccion(int dir);
    /*
    Comprueba si puede caminar en la dirección actual.
    */
    bool canWalk();
    /*
    Camina hacia el siguiente Grid la dirección actual.
    */
    void walk();
    /*
    Método que define la dirección de la unidad y de su animación.
    */
    void setDireccion(eDir dir);

	// GETTERS
	sf::FloatRect getFloatRect();
	sf::Vector2f getPosition();
	sf::Vector2f getOrigin();
	int getDireccion();
    int getFacingDir();
};

