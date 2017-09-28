#include "player.h"



Player::Player(float rad)
{
	image = sf::CircleShape(rad, 30);
	image.setFillColor(sf::Color::White);
	image.setOutlineColor(sf::Color::Blue);
	image.setOutlineThickness(5);
	image.setOrigin(rad / 2, rad / 2);
	dir = sf::Vector2f(rand() % 5 - 10, rand() % 5 - 10);
	r = rad;
}

void Player::update(float accel)
{
	pos.x += dir.x*accel;
	pos.y += dir.y*accel;
	image.setPosition(pos);
}

void Player::draw(sf::RenderWindow *win)
{
	win->draw(image);
}


Player::~Player()
{
}

sf::Vector2f Player::getPos()
{
	return pos;
}

void Player::setPos(sf::Vector2f p)
{
	pos = p;
	image.setPosition(pos);
}
