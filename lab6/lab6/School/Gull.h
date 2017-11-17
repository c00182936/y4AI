#include "Pvector.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "Feesh.h"
#pragma once
#ifndef GULL_H_
#define GULL_H_
class Gull
{
public:
	Gull();
	Gull(float x, float y, int wHeight, int wWidth);

	Pvector position;
//	Pvector whalePos;
	Pvector velocity;
	Pvector acceleration;
	float maxSpeed;
	float maxForce;
	void applyForce(Pvector force);
	Pvector Separation(vector<Gull> Gull);
	Pvector Alignment(vector<Gull> Gull);
	Pvector Cohesion(vector<Gull> Gull);
	Pvector seek(Pvector v);
	void run(vector <Gull> v);
	void update();
	void flock(vector <Gull> v);
	void borders();
	float angle(Pvector v);
	std::vector<Feesh>fishVec;
private:
	int winHeight;
	int winWidth;
	int topLimit, topBound1, topbound2;
	int bottomLimit, bottomBound1, bottomBound2;
	int boundInc;

};

#endif