#include "seekAI.h"



seekAI::seekAI(float rad, sf::Vector2u bounds, Player *ref)
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
	direction = rand() % 360;
	//findDirection();
	r = rad;
	screenBoundary = bounds;
}

void seekAI::draw(sf::RenderWindow * win)
{
	win->draw(spr);
}

void seekAI::update()
{
	KinematicSeek();
	pos.x += dir.x * 2;
	pos.y += dir.y * 2;
	spr.setPosition(pos);

}

void seekAI::setPos(sf::Vector2f p)
{
	pos = p;
	
}

sf::Vector2f seekAI::getPos()
{
	return sf::Vector2f();
}

void seekAI::KinematicSeek()
{
}

void seekAI::KinematicArrive()
{
}

void seekAI::kinematicAvoid(sf::Vector2f hyp)
{
}


seekAI::~seekAI()
{
}

void seekAI::findDirection()
{
	float tempDir = direction*(std::atan(1.0) * 4);
	tempDir /= 180;
	//dir.x = sin(direction);
	//dir.y = cos(direction);
	dir.x = cos(tempDir);
	dir.y = sin(tempDir);
	spr.setRotation(direction);
}
