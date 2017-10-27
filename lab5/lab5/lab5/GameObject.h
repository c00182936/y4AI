#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	virtual void update() = 0;
	virtual void render(sf::RenderWindow &r) = 0;
};

