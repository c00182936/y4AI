#pragma once
#include "GameObject.h"
class AI :
	public GameObject
{
public:
	AI();
	~AI();
	void update();
	void render(sf::RenderWindow &r);
};

