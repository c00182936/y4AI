#include "AI.h"



AI::AI(float rad,sf::Vector2u bounds, Player *ref)
{
	/*image = sf::CircleShape(rad, 5);
	image.setFillColor(sf::Color::Black);
	image.setOutlineColor(sf::Color::Red);
	image.setOutlineThickness(10);*/
	playerRef = ref;
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
	screenBoundary = bounds;
}

void AI::draw(sf::RenderWindow *win)
{
	win->draw(spr);
}

void AI::update()
{
	KinematicSeek();
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

void AI::KinematicWander()
{
	



}

void AI::KinematicSeek()
{
	float hypotenuse;
	sf::Vector2f hyp;
	hyp = playerRef->getPos() - pos;
	hypotenuse = hypotf(hyp.x, hyp.y);
	//normalize it
	hyp.x /= hypotenuse;
	hyp.y /= hypotenuse;
	dir = hyp;
	direction = atan2(hyp.x, hyp.y);
	direction *= 180;
	spr.setRotation(direction);
}

void AI::KinematicArrive()
{
}

void AI::findNewDirection()
{

}

void AI::kinematicAvoid()
{

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

void AI::findDirection(sf::Vector2f hyp)
{
	float tempDir = direction*(std::atan(1.0) * 4);
	tempDir /= 180;
	//dir.x = sin(direction);
	//dir.y = cos(direction);
	dir.x = cos(tempDir);
	dir.y = sin(tempDir);
	spr.setRotation(direction);
}
