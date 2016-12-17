#pragma once

#include <memory>
#include "GameBoard.h"

namespace Chess::DataObjects
{
	class ChessRullEngine
	{
		std::weak_ptr<GameBoard> _gameBoard;

		void Move(GamePosition& start, GamePosition& end);

	public:
		ChessRullEngine(std::weak_ptr<GameBoard> gameBoard);
		~ChessRullEngine();

		bool TryMakeMove(GamePosition& start, GamePosition& end);
		bool CanMakeMove(GamePosition& start, GamePosition& end) const;
	};
}