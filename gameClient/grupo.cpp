#include "Grupo.h"

Grupo::Grupo() :
sf::Drawable()
{
}

void Grupo::draw(sf::RenderTarget& Tar, sf::RenderStates &states) const {
	
	// TODO: implementar esta clase, da error en el begin()
	
	//for (std::vector<sf::Drawable*>::iterator i = begin(); i != end(); ++i) {
	//	Tar.draw(*i);
	//}
}

Grupo::~Grupo()
{
	for (std::vector<sf::Drawable*>::iterator i = _drawables.begin(); i != _drawables.end(); ++i) {
		delete *i;
	}
}
