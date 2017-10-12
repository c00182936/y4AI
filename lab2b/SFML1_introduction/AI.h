#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <math.h>
#include "player.h"
class AI
{
public:
	AI(float rad,sf::Vector2u bounds, Player *ref);
	int state;//seeking=1, arrive=2, avoid=3
	int type;
	void draw(sf::RenderWindow *win);
	void update();
	void setPos(sf::Vector2f p);
	sf::Vector2f getPos();
	sf::CircleShape image;
	void KinematicWander();
	void KinematicSeek();
	void KinematicArrive();
	void findNewDirection();
	void kinematicAvoid();
	void checkArrived();
	float r;
	~AI();
private:
	Player *playerRef;
	sf::Vector2f pos;
	sf::Vector2f dir;
	sf::Vector2f targetPos;
	float direction;
	void clampDirection();
	void findDirection();
	void findDirection(sf::Vector2f hyp);
	sf::Sprite spr;
	sf::Texture tex;
	sf::Vector2u screenBoundary;
	int velocity;
	int chaseVelocity=3;
	int arriveVelocity=1;
	int avoidVelocity=0.1;
};

