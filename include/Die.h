#ifndef DIE_H
#define DIE_H

class Die
{
private:
	int sides;
	int faceValue;

public:

	// Constructors

	Die();

	// Getters
	int getSides() const;
	int getFaceValue() const;

	// Setters

	void setSides(int new_sides);
	void setFaceValue(int new_faceValue);

	// Actions

	void roll();
};

#endif