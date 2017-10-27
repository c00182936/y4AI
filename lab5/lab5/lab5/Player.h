#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();
	void update();
	void render(sf::RenderWindow &r);
};

