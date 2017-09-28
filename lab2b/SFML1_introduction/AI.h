#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <math.h>
class AI
{
public:
	AI(float rad,sf::Vector2u bounds);
	void draw(sf::RenderWindow *win);
	void update();
	void setPos(sf::Vector2f p);
	sf::Vector2f getPos();
	sf::CircleShape image;
	void KinematicWander();
	void KinematicSeek();
	void KinematicArrive();
	float r;
	~AI();
private:
	sf::Vector2f pos;
	sf::Vector2f dir;
	sf::Vector2f targetPos;
	float direction;
	void clampDirection();
	void findDirection();
	sf::Sprite spr;
	sf::Texture tex;
	sf::Vector2u screenBoundary;
};

