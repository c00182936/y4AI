#include "Squabble.h"



Squabble::Squabble()
{
	
}


int Squabble::getSize()
{
	return squabble.size();
}

void Squabble::setFishVec()
{
	for (size_t i = 0; i < squabble.size(); i++)
	{
		squabble[i].fishVec = *schoolRef;
	}
	
}

Gull Squabble::getGulls(int i)
{
	return squabble[i];
}

void Squabble::addGulls(Gull b)
{
	squabble.push_back(b);
}

void Squabble::flocking()
{
	for (size_t i = 0; i < squabble.size(); i++)
	{

		squabble[i].run(squabble);
	}
}

void Squabble::swarming()
{
}

Squabble::~Squabble()
{
}
