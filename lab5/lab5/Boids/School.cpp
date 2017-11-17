#include "School.h"



School::School()
{

}


int School::getSize()
{
	return school.size();
}

Feesh School::getFeesh(int i)
{
	return school[i];
}

void School::addFeesh(Feesh b)
{
	school.push_back(b);
}

void School::flocking()
{
	for (size_t i = 0; i < school.size(); i++)
	{
		school[i].run(school);
		school[i].whalePos = whalePos;
	}
}

void School::swarming()
{
}

School::~School()
{
}
