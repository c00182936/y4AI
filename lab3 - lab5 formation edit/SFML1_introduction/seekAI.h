#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <math.h>
#include "player.h"

class seekAI
{
public:
	seekAI(float rad, sf::Vector2u bounds, Player *ref);
	int state;//seeking=1, arrive=2, avoid=3
	int type;
	void draw(sf::RenderWindow *win);
	void update();
	void setPos(sf::Vector2f p);
	sf::Vector2f getPos();

	void KinematicSeek();

	void KinematicArrive();

	void kinematicAvoid(sf::Vector2f hyp);
	float r;
	~seekAI();
private:
	Player *playerRef;
	sf::Vector2f pos;
	sf::Vector2f dir;
	sf::Vector2f targetPos;
	float direction;
	void findDirection();

	void findDirection(sf::Vector2f hyp);
	sf::Sprite spr;
	sf::Texture tex;
	sf::Vector2u screenBoundary;
	int velocity;
	int chaseVelocity = 2;
	int arriveVelocity = 1;
	int stopVelocity = 0;
};

