#include <iostream>
#include <ctime>

#include "include/GameLogic.h"
#include "include/Die.h"
#include "include/ConsoleUI.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	ConsoleUI consoleUI;

	consoleUI.startGame();

	return 0;
}
