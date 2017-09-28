#pragma once
#include<SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <math.h>
class Player
{
public:
	Player(float rad);
	void update(float accel);
	void draw(sf::RenderWindow *win);
	~Player();
	sf::Vector2f getPos();
	void setPos(sf::Vector2f p);
	float r;
	sf::CircleShape image;
private:
	sf::Vector2f pos;
	sf::Vector2f dir;


};

