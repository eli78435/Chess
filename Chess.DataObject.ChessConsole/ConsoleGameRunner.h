#pragma once

#include <memory>
#include "../Chess.DataObjects/ActiveGame.h"

using namespace std;
using namespace Chess::DataObjects;

void StringToLower(string& originalString);

class ConsoleGameRunner
{
	bool _runGameLoop = true;
	shared_ptr<ActiveGame> _initializedGame;

	void PrintHeader() const;
	void MakeMove();
	bool TryParse(string & userMove, GamePosition & start, GamePosition & end);
	void PrintBoard() const;
	void PrintSuffix() const;

public:
	ConsoleGameRunner(shared_ptr<ActiveGame> initializedGame);

	void Run();
};