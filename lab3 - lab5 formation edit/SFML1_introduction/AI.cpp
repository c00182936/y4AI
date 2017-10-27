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
	//r = rad;
	screenBoundary = bounds;
}

void AI::draw(sf::RenderWindow *win)
{
	win->draw(spr);
}

void AI::update()
{
	checkArrived();
	if (state == 1)
	{
		KinematicSeek();
	}
	else if (state == 2)
	{
		KinematicSeek();
	}
	else if (state == 3)
	{
		kinematicAvoid();
	}
	pos.x += dir.x * velocity;
	pos.y += dir.y * velocity;
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
	direction = atan2(hyp.y, hyp.x);
	hyp.x /= hypotenuse;
	hyp.y /= hypotenuse;
	dir = hyp;

	//direction *= 180;
	//spr.setRotation(direction);
}

void AI::KinematicArrive()
{
}

void AI::findNewDirection()
{

}

void AI::kinematicAvoid()
{
	float tempDir = direction*(std::atan(1.0) * 4);
	tempDir /= 180;
	//dir.x = sin(direction);
	//dir.y = cos(direction);
	dir.x = cos(tempDir);
	dir.y = sin(tempDir);
	spr.setRotation(direction);
}

void AI::checkArrived()
{

	sf::Vector2f dist = pos - playerRef->getPos();
	float distance = sqrt(dist.x*dist.x + dist.y*dist.y);
	if (distance > r * 4 + playerRef->r)
	{
		state = 1;
		velocity = chaseVelocity;
	}
	else if (distance > r*2 + playerRef->r&&distance < r * 4 + playerRef->r)
	{
		state = 2;
		velocity = arriveVelocity;
	}
	else
	{
		state = 3;
		velocity = avoidVelocity;
	}



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
