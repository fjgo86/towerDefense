#include <iostream>

#include "AnimatedSprite.h"
#include "../Game.h"


AnimatedSprite::AnimatedSprite(std::string nombre, const char * rutaImagen) {
    try {
        sfTexture = gGame._textureManager->loadFromFile(nombre, rutaImagen);    // Si hay cualquier error con la animación, se borra la Unit y se bloquea todo el código.
    }
    catch (...) {
        std::cout << "Error cargando fichero '" << rutaImagen << "'" << std::endl;
        delete this;
        return;
    }

    sizeX = sfTexture->getSize().x / 3;
    sizeY = sfTexture->getSize().y / 4;
    _speed = 0;
    _isStopped = false;
    _dir = DIR_N;
}

AnimatedSprite::AnimatedSprite() {
}

AnimatedSprite::~AnimatedSprite() {
}

void AnimatedSprite::update(const float elapsed) {
    lastTick += elapsed;	// Actualización del contador de tick.
    if (lastTick < 0.2f)	// Si la animación lleva menos de 0.2 ticks (segundos) sin actualizarse se detiene el código.
        return;
    frameActual++;
    if (frameActual >= 4)	// Cada ciclo de animación tiene 4 frames (del 0 al 3), cuando se pasa del cuarto se resetea.
        frameActual = 0;
    lastTick = 0.0f;
    walk();
}

void AnimatedSprite::setPosition(float x, float y) {
    sfSprite.setPosition(x, y);
}

void AnimatedSprite::setOrigin(bool centered) {
    if (centered) {
        setOrigin(sfSprite.getGlobalBounds().width / 2, sfSprite.getGlobalBounds().height / 2);
    }
}

void AnimatedSprite::setOrigin(float x, float y) {	// Este método (con el dragón) pasando x=100, y=100 lo centra correctamente.

    sfSprite.setOrigin(sf::Vector2f(x, y));
}

void AnimatedSprite::draw() {
    int frame = frameList[frameActual];
    sf::IntRect rectSourceSprite(frame * sizeX,	// Multiplicando el frame actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
        getFacingDir() * sizeY,					// Multiplicando la dirección (que también representa cada fila de frames) actual por el tamaño de cada frame tenemos la posicion del primer pixel del frame a mostrar.
        sizeX,	// tamaño maximo del frame.
        sizeY);
    sfSprite.setTexture(*sfTexture);
    sfSprite.setTextureRect(rectSourceSprite);
    gGame._gameWindow.draw(sfSprite);
}

bool AnimatedSprite::canWalk() {
    if (_isStopped || _speed <= 0.0f)
        return false;

    unsigned int MAPBOUND_X_MIN = 10;
    unsigned int MAPBOUND_X_MAX = gGame._screenHeight - 10;
    unsigned int MAPBOUND_Y_MIN = 10;
    unsigned int MAPBOUND_Y_MAX = gGame._screenWidth - 10;

    switch (_dir) {
        case DIR_N:
            if (sfSprite.getPosition().y - _speed <= MAPBOUND_Y_MIN)
                return false;
            return true;
        case DIR_NE:
            if ((sfSprite.getPosition().y - _speed <= MAPBOUND_Y_MIN) || (sfSprite.getPosition().x + _speed >= MAPBOUND_X_MAX))
                return false;
            return true;
        case DIR_E:
            if (sfSprite.getPosition().x + _speed >= MAPBOUND_X_MAX)
                return false;
            return true;
        case DIR_SE:
            if ((sfSprite.getPosition().y + _speed >= MAPBOUND_Y_MAX) || (sfSprite.getPosition().x + _speed >= MAPBOUND_X_MAX))
                return false;
            return true;
        case DIR_S:
            if (sfSprite.getPosition().y + _speed >= MAPBOUND_Y_MAX)
                return false;
            return true;
        case DIR_SW:
            if ((sfSprite.getPosition().y + _speed >= MAPBOUND_Y_MAX) || (sfSprite.getPosition().x - _speed <= MAPBOUND_X_MIN))
                return false;
            return true;
        case DIR_W:
            if (sfSprite.getPosition().x - _speed <= MAPBOUND_X_MIN)
                return false;
            return true;
        case DIR_NW:
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
    if (dir < DIR_S || dir > DIR_NE) {
        std::cout << "setDirection(" << dir << ") fuera de rango" << std::endl;
        return;
    }
    _dir = (eDir)dir;
}

void AnimatedSprite::walk() {
    if (canWalk()) {
        float _posY = 0;
        float _posX = 0;
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
        sfSprite.move(_posX, _posY);
    }
}

sf::FloatRect AnimatedSprite::getFloatRect() {
    return sfSprite.getGlobalBounds();
}

sf::Vector2f AnimatedSprite::getPosition() {
    return sfSprite.getPosition();
}

sf::Vector2f AnimatedSprite::getOrigin() {
    return sfSprite.getOrigin();
}

int AnimatedSprite::getDireccion() {
    return this->_dir;
}

int AnimatedSprite::getFacingDir() {
    return this->_dir % 4;
}