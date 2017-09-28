#include "AI.h"



AI::AI(float rad)
{
	/*image = sf::CircleShape(rad, 5);
	image.setFillColor(sf::Color::Black);
	image.setOutlineColor(sf::Color::Red);
	image.setOutlineThickness(10);*/
	if (!tex.loadFromFile("ai.png"))
	{

	}
	r = tex.getSize().x / 2;
	spr.setTexture(tex);
	spr.setOrigin(r, r);
	dir = sf::Vector2f(rand() % 5 - 10, rand() % 5 - 10);
	image.setOrigin(rad / 2, rad / 2);
	direction = rand() % 360;
	findDirection();
	r = rad;
}

void AI::draw(sf::RenderWindow *win)
{
	win->draw(spr);
}

void AI::update()
{
	pos += dir;
	spr.setPosition(pos);
}

void AI::setPos(sf::Vector2f p)
{
	pos = p;
	image.setPosition(pos);
}

sf::Vector2f AI::getPos()
{
	return pos;
}


AI::~AI()
{
}

void AI::clampDirection()
{
	if (direction < 0)
	{
		direction += 360;
	}
	if (direction > 360)
	{
		direction -= 360;
	}

}

void AI::findDirection()
{
	float tempDir = direction*(std::atan(1.0) * 4);
	tempDir /= 180;
	//dir.x = sin(direction);
	//dir.y = cos(direction);
	dir.x = cos(tempDir);
	dir.y = sin(tempDir);
	spr.setRotation(direction);
}
