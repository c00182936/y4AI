#pragma once
#include <vector>
#include <iostream>
#include "Feesh.h"
#include "Pvector.h"
class School
{
public:
	School();
	//Public Variables
	vector<Feesh> school;

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
	
	Feesh getFeesh(int i);
	//Mutator Functions
	void addFeesh(Feesh b);
	void flocking();
	Pvector whalePos;
	void swarming();
	~School();
};

