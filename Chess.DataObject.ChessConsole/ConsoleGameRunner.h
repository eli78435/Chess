#pragma once

#include <memory>
#include "../Chess.DataObjects/ActiveGame.h"
#include "../Chess.DataObjects/GameBoard.h"

void StringToLower(std::string& originalString);

class ConsoleGameRunner
{
	bool _runGameLoop = true;
	std::shared_ptr<Chess::DataObjects::ActiveGame> _initializedGame;

	void PrintHeader() const;
	void MakeMove();
	bool TryParse(std::string & userMove, Chess::DataObjects::GamePosition & start, Chess::DataObjects::GamePosition & end);
	void PrintBoard() const;
	void PrintSuffix() const;

public:
	ConsoleGameRunner(std::shared_ptr<Chess::DataObjects::ActiveGame> initializedGame);

	void Run();
};