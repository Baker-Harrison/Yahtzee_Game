#include <iostream>
#include "../include/Die.h"

using namespace std;

// Constructors

Die::Die()
{
	setSides(6);
}


// Getters
int Die::getSides() const
{
	return sides;
}
int Die::getFaceValue() const
{
	return faceValue;
}

// Setters

void Die::setSides(int new_sides)
{
	sides = new_sides;
}
void Die::setFaceValue(int new_faceValue)
{
	faceValue = new_faceValue;
}

// Actions

void Die::roll()
{
	faceValue = (rand() % sides) + 1;
}
