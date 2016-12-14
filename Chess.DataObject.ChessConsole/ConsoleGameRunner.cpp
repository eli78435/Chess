#include "stdafx.h"
#include "ConsoleGameRunner.h"

using namespace std;
using namespace Chess::DataObjects;

/*///////////////////////////////////
Helpers
//////////////////////////////////*/
void StringToLower(string& originalString)
{
	std::transform(originalString.begin(), originalString.end(), originalString.begin(), ::tolower);
}



/*///////////////////////////////////
 ConsoleGameRunner
//////////////////////////////////*/
ConsoleGameRunner::ConsoleGameRunner(shared_ptr<ActiveGame> initializedGame)
	: _initializedGame(initializedGame)
{
}

void ConsoleGameRunner::Run()
{
	PrintHeader();

	while (_runGameLoop)
	{
		MakeMove();
	}

	PrintSuffix();
}

void ConsoleGameRunner::PrintHeader() const
{
	std::cout << "Chess Game Start" << std::endl;
	std::cout << "================" << std::endl;
	std::cout << std::endl;
	std::cout << "Press \'p\' to print game or enter your move." << std::endl;
	std::cout << "ex: a1->a3" << std::endl;
	std::cout << std::endl;
}

void ConsoleGameRunner::MakeMove()
{
	std::string userMove;
	std::cin >> userMove;

	StringToLower(userMove);

	if (userMove == "p")
		PrintBoard();
	else
	{
		GamePosition start; 
		GamePosition end;

		if (TryParse(userMove, start, end))
		{

		}
		else
		{
			std::cout << "Not a valid move" << std::endl;
			//std::cout << sprintf("\'%s\' is not a valid move", userMove.c_str()) << std::endl;
			std::cout << std::endl;
		}
	}
}

bool ConsoleGameRunner::TryParse(string& userMove, GamePosition& start, GamePosition& end)
{
	return false;
}

void ConsoleGameRunner::PrintBoard() const
{
	std::cout << std::endl;
	std::cout << "Print the board ..." << std::endl;
	std::cout << std::endl;
}

void ConsoleGameRunner::PrintSuffix() const
{
	std::cout << std::endl;
	std::cout << "Chess Game Ended" << std::endl;
	std::cout << std::endl;
}

