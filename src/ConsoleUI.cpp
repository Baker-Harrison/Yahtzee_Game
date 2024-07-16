#include <iostream>
#include "../include/ConsoleUI.h"
#include "../include/GameLogic.h"
#include <cstddef>


using namespace std;

// Constructor
ConsoleUI::ConsoleUI()
{

}
// Actions
void ConsoleUI::startGame()
{
	printMenu();

}


void ConsoleUI::gameLoop()
{
	GameLogic logic;

	for (int i = 0; i < logic.getNumOfRounds(); i++) {
		if (logic.getNumOfDice() - logic.getRoll().size() > 0) {
			cout << "Round " << i + 1 << endl;
			logic.playTurn();

			// cout << "Amount of Dice Left --> " << logic.getNumOfDice() - logic.getRoll().size() << endl;


			string selection;
			cout << "Do you want to set aside some dice(yes/no)?" << endl;
			cin >> selection;

			// some function that removes a select number of dice

			if (selection == "yes")
			{
				logic.removeDice(logic.getRoll());
			}
		}
	}
	cout << endl << endl;

	for (Die die: logic.getRoll())
	{
		cout << die.getFaceValue() << "   " ;
	}
	// Calculate score here
	char category;
	cout << "Which category will you score: " << endl
			<< "1. aces" << endl
			<< "2. twos" << endl
			<< "3. three" << endl
			<< "4. fours" << endl
			<< "5. fives" << endl
			<< "6. sixes" << endl;
	cin >> category;



	int num;
	num = int(category - '0');



	int count = 0;
	if (logic.findInVector(num))
	{
		for (Die die : logic.getRoll())
		{
			if (die.getFaceValue() == num)
			{
				count++;
			}

		}

		logic.setScore(num * count);

	}
	else
	{
		cout << "Invalid category, adding score of 0 to total" << endl;
		printMenu();
	}

	cout << "Total score: " << logic.getScore() << endl;

}

void ConsoleUI::printResults()
{
	printMenu();
}


void ConsoleUI::printMenu()
{
	char menuSelection;
	cout << "Select from this menu:" << endl
	     << "1.  Play Yahtzee" << endl
	     << "2.  End game" << endl;

	cin >> menuSelection;

	setMenuSelection(menuSelection);

	menuSelectionHandler();
}
void ConsoleUI::menuSelectionHandler()
{
	if ( getMenuSelection() == '1' )
	{
		gameLoop();
	}
	else if ( getMenuSelection() == '2' )
	{
		cout << "Thanks for playing my game" << endl;
		exit(0);
	}
	else
	{
		cout << endl;
		cout << "Not a valid selection. Try again!" << endl << endl;;
		printMenu();
	}
}

// Getters

char ConsoleUI::getMenuSelection()
{
	return menuSelection;
}


// Setters

void ConsoleUI::setMenuSelection(char choice) {
	menuSelection = choice;
}