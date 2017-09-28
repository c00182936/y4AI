#pragma once
#include<SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <math.h>

class Player
{
public:
	Player(float rad);
	void update();
	void draw(sf::RenderWindow *win);
	~Player();
	sf::Vector2f getPos();
	void setPos(sf::Vector2f p);
	float r;
	sf::CircleShape image;
private:
	float speed=0;
	float accel=0.5;
	float maxSpeed=10;
	float drag=1.1;
	sf::Vector2f pos;
	sf::Vector2f dir;
	float direction;
	void clampDirection();
	void findDirection();
	sf::Texture tex;
	sf::Sprite spr;
};

