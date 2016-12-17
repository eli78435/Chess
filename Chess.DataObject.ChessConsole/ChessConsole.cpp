#pragma once

#include "stdafx.h"
#include "..\Chess.DataObjects\GameBuilderBase.h"
#include "..\Chess.DataObjects\GameBuilderBase.h"
#include "ConsoleGameRunner.h"

using namespace std;
using namespace Chess::DataObjects;


int main()
{
	TwoHumanGameBuilder builder;
	builder.InitializeBoard();
	builder.BuildPlayers();

	shared_ptr<ActiveGame> activeGame = builder.Build();

	ConsoleGameRunner consoleGameRunner(activeGame);
	consoleGameRunner.Run();

    return 0;
}