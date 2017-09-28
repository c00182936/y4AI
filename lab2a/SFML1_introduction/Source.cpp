
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <iostream>

#include "AI.h"
#include "player.h"
int main()
{
	AI ai(60.0f);
	Player player(60.0f);
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "win");
	sf::RenderWindow *win = &window;
	window.setFramerateLimit(60);
	ai.setPos(sf::Vector2f((window.getSize().x / 3), window.getSize().y / 2));
	player.setPos(sf::Vector2f((window.getSize().x / 3)*2, window.getSize().y / 2));
	while (window.isOpen())
	{
		//player block
		if (player.getPos().y+player.r < 0)
		{
			player.setPos(sf::Vector2f(player.getPos().x, (window.getSize().y + player.r)));
		}
		if (player.getPos().y-player.r > window.getSize().y)
		{
			player.setPos(sf::Vector2f(player.getPos().x, player.r));
		}
		if (player.getPos().x+player.r < 0)
		{
			player.setPos(sf::Vector2f((window.getSize().x + player.r),player.getPos().y));
		}
		if (player.getPos().x - player.r > window.getSize().x)
		{
			player.setPos(sf::Vector2f(player.r, player.getPos().y));
		}
		//ai block
		if (ai.getPos().y + ai.r < 0)
		{
			ai.setPos(sf::Vector2f(ai.getPos().x, (window.getSize().y + ai.r)));
		}
		if (ai.getPos().y - ai.r > window.getSize().y)
		{
			ai.setPos(sf::Vector2f(ai.getPos().x, ai.r));
		}
		if (ai.getPos().x + ai.r < 0)
		{
			ai.setPos(sf::Vector2f((window.getSize().x + ai.r), ai.getPos().y));
		}
		if (ai.getPos().x - ai.r > window.getSize().x)
		{
			ai.setPos(sf::Vector2f(ai.r, ai.getPos().y));
		}
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		ai.update();
		player.update();
		
		ai.draw(win);
		player.draw(win);
		window.display();
		window.clear();
		
	}

	return 0;
}