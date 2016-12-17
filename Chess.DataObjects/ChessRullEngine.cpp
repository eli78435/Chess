#include "ChessRullEngine.h"

using namespace std;

namespace Chess::DataObjects
{
	ChessRullEngine::ChessRullEngine(weak_ptr<GameBoard> gameBoard) : _gameBoard(gameBoard)
	{}

	ChessRullEngine::~ChessRullEngine()
	{
	}
	
	bool ChessRullEngine::TryMakeMove(GamePosition & start, GamePosition & end) 
	{
		bool canMakeMove = CanMakeMove(start, end);
		if (canMakeMove)
			Move(start, end);

		return canMakeMove;
	}

	bool ChessRullEngine::CanMakeMove(GamePosition & start, GamePosition & end) const
	{
		return false;
	}

	void ChessRullEngine::Move(GamePosition & start, GamePosition & end)
	{
	}
}
