#ifndef CONSOLEUI_H
#define CONSOLEUI_H

class ConsoleUI
{
private:
	char menuSelection;

	char getMenuSelection();
	void setMenuSelection(char choice);
	void printResults();
	void printMenu();
	void menuSelectionHandler();
	void gameLoop();
	void isCategoryUsed(char category);


public:

	ConsoleUI();

	void startGame();




};







#endif