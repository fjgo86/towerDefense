#pragma once

#include <SFML/Graphics.hpp>

class Grupo : public sf::Drawable, std::vector<sf::Drawable*>
{
private:
	std::vector<sf::Drawable*> _drawables;

public:

	virtual void draw(sf::RenderTarget&, sf::RenderStates &states) const;

	Grupo();
	~Grupo();
};

