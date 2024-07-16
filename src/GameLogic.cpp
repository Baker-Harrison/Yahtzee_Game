#include <iostream>
#include "../include/GameLogic.h"
#include "../include/Die.h"
#include <string>

using namespace std;

GameLogic::GameLogic()
{
}

void GameLogic::removeDice(vector<Die> &roll)
{
	int selection;

	do
	{
		cout << "Remove a dice (1-5) or input -1 to exit";
		cin >> selection;

		if (selection == -1)
		{
			break;
		}
		selection--;

		swap(roll[selection], roll.back());
		roll.pop_back();

	} while (true);
}

// Getters
int GameLogic::getScore()
{
	return score;
}

// Setters
void GameLogic::setScore(int new_score)
{
	score = new_score;
}

// Actions

void GameLogic::playTurn()
{

	int sizeRemaining = numOfDice - roll.size();

	for (int i = 0; i < sizeRemaining; i++ ) {
		Die die;
		die.roll();
		roll.push_back(die);

	}


	for (Die die : roll)
	{
		cout << die.getFaceValue() << endl;
	}


}


int GameLogic::getNumOfRounds()
{
	return numOfRounds;
}

int GameLogic::getNumOfDice()
{
	return numOfDice;
}

vector<Die>& GameLogic::getRoll()
{
	return roll;
}

bool GameLogic::findInVector(int number)
{
	for (Die die : roll)
	{
		if (die.getFaceValue() == number)
		{
			return true;
		}

	}
	return false;
}

/*
void GameLogic::appendRoll(Die die)
{
	roll.push_back(die);
}
*/
