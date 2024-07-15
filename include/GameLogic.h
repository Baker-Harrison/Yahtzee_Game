#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <iostream>
#include "Die.h"
#include <vector>

using namespace std;

class GameLogic
{
private:
	int score;
	vector<Die> roll;
	static const int numOfDice = 5;
	static const int numOfRounds = 3;
public:
	GameLogic();

	// Getters
	int getScore();


	// Setters
	void setScore(int new_score);


	// Actions

	void playTurn();
	void removeDice(vector<Die> roll);

	int getNumOfRounds();
	int getNumOfDice();

	vector<Die> getRoll();
	void appendRoll(Die die);



};







#endif
