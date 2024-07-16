#include <iostream>
#include "../include/ConsoleUI.h"
#include "../include/GameLogic.h"



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

			cout << "Amount of Dice Left --> " << logic.getNumOfDice() - logic.getRoll().size() << endl;


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

	// Calculate score here



}

void ConsoleUI::printResults() {}


void ConsoleUI::printMenu()
{
	char menuSelection;
	cout << "Select from this menu:" << endl
	     << "1.  Play Yahtzee" << endl
	     << "2.  See recent game results" << endl
	     << "3.  End game" << endl;

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
		printResults();
	}
	else if ( getMenuSelection() == '3' )
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