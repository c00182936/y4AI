#include "player.h"



Player::Player(float rad)
{
	srand(time(NULL));
	/*
	image = sf::CircleShape(rad, 3);
	image.setFillColor(sf::Color::White);
	image.setOutlineColor(sf::Color::Blue);
	image.setOutlineThickness(5);
	image.setOrigin(rad / 2, rad / 2);*/
	//dir = sf::Vector2f(rand() % 5 - 10, rand() % 5 - 10);
	if (!tex.loadFromFile("player.png"))
	{
		
	}
	r = tex.getSize().x/2;
	spr.setTexture(tex);
	spr.setOrigin(r, r);
	direction = 0;

	direction = rand() % 360;
	direction -= 90;
	findDirection();
	//r = rad;
}

void Player::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction -= 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction += 5;
	}
	if (speed > maxSpeed*-1&&speed<maxSpeed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			speed += accel;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			speed -= accel;
		}	
	

	}
	else if(speed>maxSpeed)
	{
		speed = maxSpeed;
	
	}
	else if(speed<maxSpeed*-1)
	{
		speed = maxSpeed;
	}

	speed /= drag;
//	speed = clamp(speed, maxSpeed*-1, maxSpeed);

	findDirection();

	pos.x += dir.x*speed;
	pos.y += dir.y*speed;
	spr.setPosition(pos);
	
}

void Player::draw(sf::RenderWindow *win)
{
	win->draw(spr);
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

void Player::clampDirection()
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

void Player::findDirection()
{//std::atan(1.0)*4; for pi
	float tempDir = direction*(std::atan(1.0) * 4);
	tempDir /= 180;
	//dir.x = sin(direction);
	//dir.y = cos(direction);
	dir.x = cos(tempDir);
	dir.y = sin(tempDir);
	spr.setRotation(direction);
}
