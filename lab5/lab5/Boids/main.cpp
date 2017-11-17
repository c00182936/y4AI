#include <iostream>
#include <vector>
#include <math.h>
#include "Boid.h"
#include "Whale.h"
#include "School.h"
#include "Feesh.h"
#include "Squabble.h"
#include "Gull.h"
#include "Pvector.h"
#include "Flock.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <string>
using namespace std;

/*
Brief description of Boid Class:
// This file acts as the main for our boids project. Here, we utilize the SFML
// library, import boids and flock classes, and run the program.-
*/

int main()
{
	float boidsSize = 3;
//	string action = "flock";
	int fishNum = 50;

	//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	const int window_height = desktop.height/1.5;
	const int window_width = desktop.width/1.5;
	sf::RectangleShape sea;
	sf::RectangleShape sky;
	Whale shamu(rand() % window_width, window_height - window_height / 4,window_height,window_width);
	sea.setPosition(0, window_height / 2);
	sea.setSize(sf::Vector2f(window_width, window_height / 2));
	sky.setPosition(0, 0);
	sky.setSize(sf::Vector2f(window_width, window_height / 2));
	sea.setFillColor(sf::Color(21, 45, 165));
	sky.setFillColor(sf::Color(61, 177, 255));
	//Having the style of "None" gives a false-fullscreen effect for easier closing and access.
	//No FPS limit of V-sync setting needed for it may cause unnecessary slowdown.
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "feesh and birbs"); 

	//Create flock, vector of shapes, and initialize boids
	//Flock flock;
	School school;
	Squabble squabble;
	vector<sf::CircleShape> shapes;
	shapes.reserve(fishNum);
	school.school.reserve(fishNum);

	vector<sf::CircleShape> gullShapes;
	gullShapes.reserve(fishNum);
	squabble.squabble.reserve(fishNum);
	//at 10, the program runs faster, flock seems to move too quickly to join up together, or the flock is too small for them to group properly
	//at 300, the program runs much slower when running the flocking behaviour
	//feesh
	for (int i = 0; i < fishNum; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		//Boid b(window_width / 3, window_height / 3); //Starts all boids in the center of the screen
		Feesh f(0+window_width / 3, window_height - window_height / 4,window_height,window_width);
		sf::CircleShape shape(8,3); //Shape with a radius of 10 and 3 points (Making it a triangle)

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		//shape.setOutlineColor(sf::Color(0,255,0));
		shape.setFillColor(sf::Color(173,182,198));
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(1);
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		//flock.addBoid(b);
		school.addFeesh(f);
		shapes.push_back(shape);
		Gull g(window_width - window_width / 3, window_height / 4, window_height, window_width);
		sf::CircleShape gShape(boidsSize, 3);
		shape.setFillColor(sf::Color(173, 182, 198));
		shape.setOutlineColor(sf::Color(206,124,24));
		shape.setOutlineThickness(1);
		shape.setRadius(boidsSize);
		squabble.addGulls(g);
		gullShapes.push_back(gShape);
	}
	sf::CircleShape whaleShape(10, 3);
	whaleShape.setRadius(10);
	whaleShape.setPosition(sf::Vector2f(shamu.position.x, shamu.position.y));
	whaleShape.setOutlineColor(sf::Color(255, 255, 255));
	whaleShape.setFillColor(sf::Color(20, 20, 20));
	whaleShape.setOutlineThickness(3);
	whaleShape.setOrigin(5, 5);
	squabble.schoolRef = &school.school;
	squabble.setFishVec();
	while (window.isOpen())
	{	
		//Event used to close program when window is closed
		sf::Event event;
		while (window.pollEvent(event))
		{
			//"close requested" event: we close the window
			//Implemented alternate ways to close the window. (Pressing the escape, X, and BackSpace key also close the program.)
			if ((event.type == sf::Event::Closed) || 
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::Escape) ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::BackSpace) ||
				(event.type == sf::Event::KeyPressed &&
				 event.key.code == sf::Keyboard::X))
			{
				window.close();
			}
		//	if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
		//		if (action == "flock")
		//			action = "swarm";
		//		else
		//			action = "flock";

		}

		//check for mouse click, draws and adds boid to flock if so.
		//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		//{
		//	//Gets mouse coordinates, sets that as the location of the boid and the shape
		//	sf::Vector2i mouseCoords = sf::Mouse::getPosition(window);
		//	Boid b(mouseCoords.x, mouseCoords.y, true);
		//	sf::CircleShape shape(10,3);

		//	//Changing visual properties of newly created boid
		//	shape.setPosition(mouseCoords.x, mouseCoords.y);
		//	shape.setOutlineColor(sf::Color(255, 0, 0));
		//	shape.setFillColor(sf::Color(255, 0, 0));
		//	shape.setOutlineColor(sf::Color::White);
		//	shape.setOutlineThickness(1);
		//	shape.setRadius(boidsSize);

		//	//Adds newly created boid and shape to their respective data structure
		//	flock.addBoid(b);
		//	shapes.push_back(shape);

		//	//New Shape is drawn
		//	window.draw(shapes[shapes.size()-1]);
		//}
		//Clears previous frames of visualization to not have clutter. (And simulate animation)
		window.clear();
			window.draw(sea);
			window.draw(sky);
			whaleShape.setPosition(shamu.position.x, shamu.position.y);
			float whaleTheta = shamu.angle(shamu.velocity);
			whaleShape.setRotation(whaleTheta);
			float temp1, temp2;
			fishNum = shapes.size();
			//to kill a fish when touched by the whale
			for (size_t i = 0; i < fishNum; i++)
			{
				temp1 = school.getFeesh(i).position.x - shamu.position.x;
				temp1 *= temp1;
				temp2 = school.getFeesh(i).position.y - shamu.position.y;
				temp2 *= temp2;
				temp2 += temp1;
				sqrtf(temp2);
				//13 radius of whale and fish quadrupled and then a little more 
				if (temp2 < 60 && i<school.school.size() && i<shapes.size())
				{
					if (i < shapes.size())
					{
						fishNum--;
						shapes.erase(shapes.begin() + i);
						school.school.erase(school.school.begin() + i);
						
					}

				}
			}
			
		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < shapes.size(); i++)
		{

			window.draw(shapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			//shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);
			shapes[i].setPosition(school.getFeesh(i).position.x, school.getFeesh(i).position.y);
			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			//theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
			theta = school.getFeesh(i).angle(school.getFeesh(i).velocity);
			shapes[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (shapes[i].getPosition().x > window_width)
				shapes[i].setPosition(shapes[i].getPosition().x - window_width, shapes[i].getPosition().y);
			// If boid exits bottom boundary
			if (shapes[i].getPosition().y > window_height)
				shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (shapes[i].getPosition().x < 0)
				shapes[i].setPosition(shapes[i].getPosition().x + window_width, shapes[i].getPosition().y);
			// If boid exits top boundary
			if (shapes[i].getPosition().y < 0)
				shapes[i].setPosition(shapes[i].getPosition().x, shapes[i].getPosition().y + window_height);
		}
		for (int i = 0; i < gullShapes.size(); i++)
		{

			window.draw(gullShapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			//shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);
			gullShapes[i].setPosition(squabble.getGulls(i).position.x, squabble.getGulls(i).position.y);
			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			//theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
			theta = squabble.getGulls(i).angle(squabble.getGulls(i).velocity);
			gullShapes[i].setRotation(theta);

			// These if statements prevent boids from moving off the screen through warpping
			// If boid exits right boundary
			if (gullShapes[i].getPosition().x > window_width)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x - window_width, gullShapes[i].getPosition().y);
			// If boid exits bottom boundary
			if (gullShapes[i].getPosition().y > window_height)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x, gullShapes[i].getPosition().y - window_height);
			// If boid exits left boundary
			if (gullShapes[i].getPosition().x < 0)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x + window_width, gullShapes[i].getPosition().y);
			// If boid exits top boundary
			if (gullShapes[i].getPosition().y < 0)
				gullShapes[i].setPosition(gullShapes[i].getPosition().x, gullShapes[i].getPosition().y + window_height);
		}
		window.draw(whaleShape);

		//Applies the three rules to each boid in the flock and changes them accordingly.
		//if (action == "flock")
		//	flock.flocking();
		//else
		//	flock.swarming();

		school.flocking();
		squabble.flocking();
		shamu.run(school.school);
		school.whalePos = shamu.position;

		//Updates the window with current values of any data that was modified.
		window.display();

	//This loop continues until window is closed. Continues the process of updating, drawing, rendering the boids, and the window.
	}
	return 0;

}