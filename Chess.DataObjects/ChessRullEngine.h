#pragma once

#include <memory>
#include "GameBoard.h"

using namespace std;

namespace Chess::DataObjects
{
	class ChessRullEngine
	{
		weak_ptr<GameBoard> _gameBoard;

		void Move(GamePosition& start, GamePosition& end);

	public:
		ChessRullEngine(weak_ptr<GameBoard> gameBoard);
		~ChessRullEngine();

		bool TryMakeMove(GamePosition& start, GamePosition& end);
		bool CanMakeMove(GamePosition& start, GamePosition& end) const;
	};
}