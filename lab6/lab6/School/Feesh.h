#include <SFML\System.hpp>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "Pvector.h"
#ifndef FEESH_H_
#define FEESH_H_

class Feesh
{
public:
	Feesh();
	Feesh(float x, float y, int wHeight, int wWidth);
	~Feesh();
	Pvector position;
	Pvector whalePos;
	Pvector velocity;
	Pvector acceleration;
	float maxSpeed;
	float maxForce;
	void applyForce(Pvector force);
	Pvector Separation(vector<Feesh> feesh);
	Pvector Alignment(vector<Feesh> feesh);
	Pvector Cohesion(vector<Feesh> feesh);
	Pvector seek(Pvector v);
	void run(vector <Feesh> v);
	void update();
	void flock(vector <Feesh> v);
	void borders();
	float angle(Pvector v);

private:
	int winHeight;
	int winWidth;
	int topLimit, topBound1, topbound2;
	int bottomLimit,bottomBound1, bottomBound2;
	int boundInc;
};

#endif