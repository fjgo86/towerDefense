#include "AnimatedSprite.h"
#include "../Game.h"
#include <iostream>


AnimatedSprite::AnimatedSprite(std::string nombre, const char * rutaImagen)
{
	try {
		sfTexture = gGame.pTextureManager->loadFromFile(nombre, rutaImagen);	// Si hay cualquier error con la animación, se borra la Unit y se bloquea todo el código.
	}
	catch (...)
	{
		std::cout << "Error cargando fichero '" << rutaImagen << "'" << std::endl;
		delete this;
		return;
	}

	sizeX = sfTexture.getSize().x / 3;
	sizeY = sfTexture.getSize().y / 4;
    _speed = 0;
    _isStopped = false;
    _dir = DIR_N;
}

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update(const float elapsed)
{
	lastTick += elapsed;	// Actualización del contador de tick.
	if (lastTick < 0.2f)	// Si la animación lleva menos de 0.2 ticks (segundos) sin actualizarse se detiene el código.
		return;
	//std::cout << "Animando " << frameActual << "("<< frameList[frameActual] <<")"<< std::endl;
	frameActual++;
	if (frameActual >= 4)	// Cada ciclo de animación tiene 4 frames (del 0 al 3), cuando se pasa del cuarto se resetea.
		frameActual = 0;
	lastTick = 0.0f;
    walk();
}

void AnimatedSprite::setPosition(float x, float y)
{
	sfSprite.setPosition(x, y);
}

void AnimatedSprite::setOrigin(bool centered)
{
	if (centered) {
		setOrigin(sfSprite.getGlobalBounds().width / 2, sfSprite.getGlobalBounds().height / 2);
	}
}

void AnimatedSprite::setOrigin(float x, float y)		// Este método (con el dragón) pasando x=100, y=100 lo centra correctamente.
{
	sfSprite.setOrigin(sf::Vector2f(x, y));
}

void AnimatedSprite::draw() {
	int frame = frameList[frameActual];
	sf::IntRect rectSourceSprite(frame * sizeX,	// Multiplicando el frame actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		direccion * sizeY,	// Multiplicando la dirección (que también representa cada fila de frames) actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
		sizeX,	// tamaño maximo del frame.
		sizeY);
	//sf::Sprite sprite(sfTexture, rectSourceSprite);		// He comentado esta línea para utilizar sfSprite, y poder acceder a él desde el resto de la clase
	sfSprite.setTexture(sfTexture);
	sfSprite.setTextureRect(rectSourceSprite);
	gGame.pGameWindow.draw(sfSprite);
}

bool AnimatedSprite::canWalk() {
    if (_isStopped || _speed <= 0.0f)
        return false;

    unsigned int MAPBOUND_X_MIN = 10;
    unsigned int MAPBOUND_X_MAX = gGame.iScreenHeight - 10;
    unsigned int MAPBOUND_Y_MIN = 10;
    unsigned int MAPBOUND_Y_MAX = gGame.iScreenWidth - 10;

    switch (_dir) {
        case DIR_N:
            std::cout << "WalkCheck1" << std::endl;
            if (sfSprite.getPosition().y - _speed <= MAPBOUND_Y_MIN)
                return false;
            return true;
        case DIR_NE:
            std::cout << "WalkCheck2" << std::endl;
            if ((sfSprite.getPosition().y - _speed <= MAPBOUND_Y_MIN) || (sfSprite.getPosition().x + _speed >= MAPBOUND_X_MAX))
                return false;
            return true;
        case DIR_E:
            std::cout << "WalkCheck2" << std::endl;
            if (sfSprite.getPosition().x + _speed >= MAPBOUND_X_MAX)
                return false;
            return true;
        case DIR_SE:
            std::cout << "WalkCheck5" << std::endl;
            if ((sfSprite.getPosition().y + _speed >= MAPBOUND_Y_MAX) || (sfSprite.getPosition().x + _speed >= MAPBOUND_X_MAX))
                return false;
            return true;
        case DIR_S:
            std::cout << "WalkCheck4" << std::endl;
            if (sfSprite.getPosition().y + _speed >= MAPBOUND_Y_MAX)
                return false;
            return true;
        case DIR_SW:
            std::cout << "WalkCheck6" << std::endl;
            if ((sfSprite.getPosition().y + _speed >= MAPBOUND_Y_MAX) || (sfSprite.getPosition().x - _speed <= MAPBOUND_X_MIN))
                return false;
            return true;
        case DIR_W:
            std::cout << "WalkCheck2" << std::endl;
            if (sfSprite.getPosition().x - _speed <= MAPBOUND_X_MIN)
                return false;
            return true;
        case DIR_NW:
            std::cout << "WalkCheck3" << std::endl;
            if ((sfSprite.getPosition().y - _speed <= MAPBOUND_Y_MIN) || (sfSprite.getPosition().x - _speed <= MAPBOUND_X_MIN))
                return false;
            return true;
    }
    return true;
}

void AnimatedSprite::setDireccion(eDir dir) {
    _dir = dir;
}

void AnimatedSprite::setDireccion(int dir) {
    if (dir < DIR_N || dir > DIR_NW) {
        std::cout << "setDirection(" << dir << ") fuera de rango" << std::endl;
        return;
    }
    _dir = (eDir)dir;
}

void AnimatedSprite::walk() {
    std::cout << "Walk1" << std::endl;
    if (canWalk()) {
        std::cout << "Walk2" << std::endl;
        float _posY = sfSprite.getPosition().y;
        float _posX = sfSprite.getPosition().x;
        switch (_dir) {
            case DIR_N:
                _posY -= _speed;
                break;
            case DIR_NE:
                _posY -= _speed;
                _posX += _speed;
                break;
            case DIR_E:
                _posX += _speed;
                break;
            case DIR_SE:
                _posY += _speed;
                _posX += _speed;
                break;
            case DIR_S:
                _posY += _speed;
                break;
            case DIR_SW:
                _posY += _speed;
                _posX -= _speed;
                break;
            case DIR_W:
                _posX -= _speed;
                break;
            case DIR_NW:
                _posY -= _speed;
                _posX -= _speed;
                break;
        }
        std::cout << "Walk3 = " << _posX << ", " << _posY << std::endl;
        setPosition(_posX, _posY);
    }
}

sf::FloatRect AnimatedSprite::getFloatRect()
{
	return sfSprite.getGlobalBounds();
}

sf::Vector2f AnimatedSprite::getPosition()
{
	return sfSprite.getPosition();
}

sf::Vector2f AnimatedSprite::getOrigin()
{
	return sfSprite.getOrigin();
}

int AnimatedSprite::getDireccion()
{
	return this->direccion;
}