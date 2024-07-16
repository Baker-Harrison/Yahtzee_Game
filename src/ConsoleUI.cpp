#include <iostream>
#include "../include/ConsoleUI.h"
#include "../include/GameLogic.h"
#include <cstddef>
#include <vector>


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
	bool categoriesUsed[6] = {false, false, false, false, false, false};

	for (int round = 0; round < 6; round++) {
		cout << "Round " << round + 1 << endl;

		for (int i = 0; i < logic.getNumOfRounds(); i++) {
			if (logic.getNumOfDice() - logic.getRoll().size() > 0) {
				logic.playTurn();

				string selection;
				cout << "Do you want to set aside some dice (yes/no)? ";
				cin >> selection;

				if (selection == "yes") {
					logic.removeDice(logic.getRoll());
				}
			}
		}

		cout << endl;
		for (Die die : logic.getRoll()) {
			cout << die.getFaceValue() << "   ";
		}
		cout << endl;

		// Select category and calculate score
		int category = 0;
		bool validCategory = false;

		while (!validCategory) {
			cout << "Which category will you score (or press any other number to leave game):" << endl
			     << "1. aces (Availability: " << (categoriesUsed[0] ? "used" : "available") << ")" << endl
			     << "2. twos (Availability: " << (categoriesUsed[1] ? "used" : "available") << ")" << endl
			     << "3. threes (Availability: " << (categoriesUsed[2] ? "used" : "available") << ")" << endl
			     << "4. fours (Availability: " << (categoriesUsed[3] ? "used" : "available") << ")" << endl
			     << "5. fives (Availability: " << (categoriesUsed[4] ? "used" : "available") << ")" << endl
			     << "6. sixes (Availability: " << (categoriesUsed[5] ? "used" : "available") << ")" << endl;
			cin >> category;

			if (category < 1 || category > 6) {
				cout << "Exiting game." << endl;
				return;
			} else if (categoriesUsed[category - 1]) {
				cout << "Category already used. Please choose a different category." << endl;
			} else {
				// Check if the category is present in the roll
				bool categoryPresent = false;
				for (Die die : logic.getRoll()) {
					if (die.getFaceValue() == category) {
						categoryPresent = true;
						break;
					}
				}

				if (categoryPresent) {
					categoriesUsed[category - 1] = true;
					validCategory = true;

					// Calculate the score for the selected category
					int num = category;
					int count = 0;



					// Calculate score
					for (Die die : logic.getRoll()) {
						if (die.getFaceValue() == num) {
							count++;
						}
					}

					logic.setScore(logic.getScore() + num * count);

					// Print the updated score after each round
					cout << "Updated score: " << logic.getScore() << endl;

					// Remove dice used for this category
					auto it = logic.getRoll().begin();
					while (it != logic.getRoll().end()) {
						if (it->getFaceValue() == category) {
							it = logic.getRoll().erase(it); // Erase the element and update iterator
						} else {
							++it; // Move to the next element
						}
					}

				} else {
					cout << "Category not present in roll. Please choose a different category." << endl;
				}
			}
		}

		// Print a separator for clarity
		cout << "----------------------------------------" << endl;
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