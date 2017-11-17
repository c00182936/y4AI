#include "Feesh.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "SFML\Graphics.hpp"
#define PI 3.141592635

Feesh::Feesh()
{
}

Feesh::Feesh(float x, float y, int wHeight, int wWidth)
{
	position.x = x; position.y = y; 
	winHeight = wHeight;
	winWidth = wWidth;
	maxSpeed = 5.5;
	maxForce = 0.8;
	acceleration = Pvector(0, 0);
	velocity = Pvector(rand() % 3 - 2, rand() % 3 - 2); // Allows for range of -2 -> 2
	boundInc = winHeight / 16;
	topLimit = winHeight / 2;
	topBound1 = topLimit + boundInc;
	topbound2 = topBound1 + boundInc;
	bottomLimit = winHeight;
	bottomBound1 = bottomLimit - boundInc;
	bottomBound2 = bottomBound1 - boundInc;
	whalePos = Pvector(0, 0);
}

Feesh::~Feesh()
{
}

void Feesh::applyForce(Pvector force)
{
	acceleration.addVector(force);
}

Pvector Feesh::Separation(vector<Feesh> feesh)
{
	// If the boid we're looking at is a predator, do not run the separation
	// algorithm

	// Distance of field of vision for separation between boids
	float desiredseparation = 20;

	Pvector steer(0, 0);
	int count = 0;
		if (position.y < topbound2)
		{
			acceleration.y += 0.5;
			if (position.y < topBound1)
			{
				acceleration.y += 1;
			}
				if (position.y < topLimit)
				{
					acceleration.y += 10;
				}
		}
		if (position.y > bottomBound2)
		{
			acceleration.y -= 0.5;
				if (position.y > bottomBound1)
				{
					acceleration.y -=1.5;
					if (position.y > bottomLimit)
					{
						acceleration.y -= 20;
					}
				}

		}
	// For every boid in the system, check if it's too close
	for (int i = 0; i < feesh.size(); i++)
	{
		// Calculate distance from current boid to boid we're looking at
		float d = position.distance(feesh[i].position);
		float whaleDist = position.distance(whalePos);
		if ((whaleDist > 0) && (whaleDist < desiredseparation + 10))
		{
			Pvector pred(0, 0);
			pred = pred.subTwoVector(position, whalePos);
			pred.mulScalar(500);
			steer.addVector(pred);
			count++;
		}
		// If this is a fellow boid and it's too close, move away from it
		else if ((d > 0) && (d < desiredseparation))
		{
			Pvector diff(0, 0);
			diff = diff.subTwoVector(position, feesh[i].position);
			diff.normalize();
			diff.divScalar(d);      // Weight by distance
			steer.addVector(diff);
			count++;
		}

		//// If current boid is a predator and the boid we're looking at is also
		//// a predator, then separate only slightly 
		//if ((d > 0) && (d < desiredseparation) && predator == true && boids[i].predator == true)
		//{
		//	Pvector pred2pred(0, 0);
		//	pred2pred = pred2pred.subTwoVector(location, boids[i].location);
		//	pred2pred.normalize();
		//	pred2pred.divScalar(d);
		//	steer.addVector(pred2pred);
		//	count++;
		//}
		//// If current boid is not a predator, but the boid we're looking at is
		//// a predator, then create a large separation Pvector

	}
	// Adds average difference of location to acceleration
	if (count > 0)
		steer.divScalar((float)count);
	if (steer.magnitude() > 0)
	{
		// Steering = Desired - Velocity
		steer.normalize();
		steer.mulScalar(maxSpeed);
		steer.subVector(velocity);
		steer.limit(maxForce);
	}
	return steer;
}

Pvector Feesh::Alignment(vector<Feesh> feesh)
{
	// If the boid we're looking at is a predator, do not run the alignment
	// algorithm
	//if (predator == true)
	//	return Pvector(0,0);
	float neighbordist = 50;

	Pvector sum(0, 0);
	int count = 0;
	for (int i = 0; i < feesh.size(); i++)
	{
		float d = position.distance(feesh[i].position);
		if ((d > 0) && (d < neighbordist)) // 0 < d < 50
		{
			sum.addVector(feesh[i].velocity);
			count++;
		}
	}
	// If there are boids close enough for alignment...
	if (count > 0)
	{
		sum.divScalar((float)count);// Divide sum by the number of close boids (average of velocity)
		sum.normalize();	   		// Turn sum into a unit vector, and
		sum.mulScalar(maxSpeed);    // Multiply by maxSpeed
									// Steer = Desired - Velocity
		Pvector steer;
		steer = steer.subTwoVector(sum, velocity); //sum = desired(average)  
		steer.limit(maxForce);
		return steer;
	}
	else {
		Pvector temp(0, 0);
		return temp;
	}
}

Pvector Feesh::Cohesion(vector<Feesh> feesh)
{
	// If the boid we're looking at is a predator, do not run the cohesion
	// algorithm
	//if (predator == true)
	//	return Pvector(0,0);

	float neighbordist = 50;

	Pvector sum(0, 0);
	int count = 0;
	for (int i = 0; i < feesh.size(); i++)
	{
		float d = position.distance(feesh[i].position);
		if ((d > 0) && (d < neighbordist))
		{
			sum.addVector(feesh[i].position);
			count++;
		}
	}
	if (count > 0)
	{
		sum.divScalar(count);
		return seek(sum);
	}
	else {
		Pvector temp(0, 0);
		return temp;
	}
}

Pvector Feesh::seek(Pvector v)
{
	Pvector desired;
	desired.subVector(v);  // A vector pointing from the location to the target
						   // Normalize desired and scale to maximum speed
	desired.normalize();
	desired.mulScalar(maxSpeed);
	// Steering = Desired minus Velocity
	acceleration.subTwoVector(desired, velocity);
	acceleration.limit(maxForce);  // Limit to maximum steering force
	return acceleration;
}

void Feesh::run(vector<Feesh> v)
{
	flock(v);
	update();
	borders();
}

void Feesh::update()
{
	//To make the slow down not as abrupt
	acceleration.mulScalar(.4);
	// Update velocity
	velocity.addVector(acceleration);
	// Limit speed
	velocity.limit(maxSpeed);
	position.addVector(velocity);
	// Reset accelertion to 0 each cycle
	acceleration.mulScalar(0);
}

void Feesh::flock(vector<Feesh> v)
{
	Pvector sep = Separation(v);
	Pvector ali = Alignment(v);
	Pvector coh = Cohesion(v);
	// Arbitrarily weight these forces
	sep.mulScalar(1.5);
	ali.mulScalar(1.0); // Might need to alter weights for different characteristics
	coh.mulScalar(1.0);
	// Add the force vectors to acceleration
	applyForce(sep);
	applyForce(ali);
	applyForce(coh);
}

void Feesh::borders()
{
	if (position.x < 0) position.x += winWidth;
	if (position.x > 1000) position.x -= winWidth;

}


float Feesh::angle(Pvector v)
{
	// From the definition of the dot product
	float angle = (float)(atan2(v.x, -v.y) * 180 / PI);
	return angle;
}
