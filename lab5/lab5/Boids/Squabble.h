#pragma once
#include <vector>
#include <iostream>
#include "Feesh.h"
#include "Pvector.h"
#include "Gull.h"
class Squabble
{
public:
	Squabble();
	//Public Variables
	vector<Gull> squabble;
	vector<Feesh> *schoolRef;

	//Constructors

	/*
	Commented out for now, since including destructors causes g++ to spit back
	errors.
	//Destructor
	Flock::~Flock()
	{
	//cout << "Flock is being deleted by destructor!" << endl;
	}
	*/
	//Accessor functions
	int getSize();
	void setFishVec();
	Gull getGulls(int i);
	//Mutator Functions
	void addGulls(Gull b);
	void flocking();
	Pvector whalePos;
	void swarming();
	~Squabble();
};

