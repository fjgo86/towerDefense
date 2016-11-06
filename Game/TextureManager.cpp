#include <iostream>

#include "TextureManager.h"


sf::Texture* TextureManager::loadFromFile(std::string nombre, const char * file) {
    if (exists(nombre))		// Si ya está cargada, se detiene el código.
        return getRef(nombre);
    sf::Texture* textura = new sf::Texture();
    textura->loadFromFile(file);	// Si no puede cargarla, return false.

    add(nombre, textura);		// Añade la textura.
    return getRef(nombre);
}

TextureManager::TextureManager() {

}


TextureManager::~TextureManager() {
}

void TextureManager::add(std::string nombre, sf::Texture* textura) {
    (*this)[nombre] = textura;
}

sf::Texture* TextureManager::getRef(std::string textura) {
    return (*this)[textura];
}

bool TextureManager::exists(std::string textura) {
    return count(textura) > 0;
}