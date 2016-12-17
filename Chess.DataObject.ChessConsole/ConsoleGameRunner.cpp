#pragma once

#include "stdafx.h"
#include "ConsoleGameRunner.h"
#include <algorithm>

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
	std::cout << "ex: a1-a3" << std::endl;
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
			if (_initializedGame->TryMakeMove(start, end))
			{
				if (_initializedGame->IsGameEnded())
				{
					_runGameLoop = false;
				}
			}
			else
			{
				std::cout << userMove << "is not a valid move" << std::endl;
				//std::cout << sprintf("\'%s\' is not a valid move", userMove.c_str()) << std::endl;
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << userMove << "is not a valid move" << std::endl;
			//std::cout << sprintf("\'%s\' is not a valid move", userMove.c_str()) << std::endl;
			std::cout << std::endl;
		}
	}
}

bool ConsoleGameRunner::TryParse(string& userMove, GamePosition& start, GamePosition& end)
{
	if (userMove.length() == 5)
	{
		string startMoveAsString = userMove.substr(0, 2);
		if (Chess::DataObjects::TryParse(startMoveAsString, start))
		{
			string endMoveAsString = userMove.substr(3, 2);
			if (Chess::DataObjects::TryParse(endMoveAsString, end))
			{
				return true;
			}
		}
	}

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