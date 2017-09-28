#include "AI.h"



AI::AI(float rad)
{
	image = sf::CircleShape(rad, 5);
	image.setFillColor(sf::Color::Black);
	image.setOutlineColor(sf::Color::Red);
	image.setOutlineThickness(10);
	dir = sf::Vector2f(rand() % 5 - 10, rand() % 5 - 10);
	image.setOrigin(rad / 2, rad / 2);
	rad = r;
}

void AI::draw(sf::RenderWindow *win)
{
	win->draw(image);
}

void AI::update()
{
	pos += dir;
	image.setPosition(pos);
}

void AI::setPos(sf::Vector2f p)
{
	pos = p;
	image.setPosition(pos);
}

sf::Vector2f AI::getPos()
{
	return sf::Vector2f();
}


AI::~AI()
{
}
