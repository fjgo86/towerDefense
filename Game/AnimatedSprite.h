#pragma once
#include "SFML/Graphics.hpp"

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
	int direccion = 0;						///< Direccion 0-4: 0 = SUR, 1 = OESTE, 2 = ESTE, 3 = NORTE.
	float lastTick = 0.0f;					///< Ticks desde la última vez que se actualizó la animación.
public:
	AnimatedSprite(std::string nombre, const char * rutaImagen);
	AnimatedSprite();
	~AnimatedSprite();
	void draw();							///< Dibuja el objeto en pantalla.
	void update(const float elapsed);		///< Actualiza la animación del objeto.

	// SETTERS
	void setPosition(float x, float y);		///< Cambia la posición del objeto
	void setOrigin(bool centered = true);	///< Método que mueve el origen de la esquina top-left al center del sprite
	void setOrigin(float x, float y);		///< Método sobrecargado para mover el origen a las coordenadas especificadas
	void setDireccion(int dir);				///< Método para cambiar la dirección, solo acepta enteros de 0 a 4

	// GETTERS
	sf::FloatRect getFloatRect();
	sf::Vector2f getPosition();
	sf::Vector2f getOrigin();
	int getDireccion();
};

