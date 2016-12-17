#include "ActiveGame.h"

using namespace std;

namespace Chess::DataObjects
{
	ActiveGame::ActiveGame(shared_ptr<GameBoard> gameBoard, shared_ptr<ChessPlayer> whitePlayer, shared_ptr<ChessPlayer> blackPlayer)
		: _gameBoard(gameBoard), _whitePlayer(whitePlayer), _blackPlayer(blackPlayer)
	{
		_activePlayer = _whitePlayer;
	}

	ActiveGame::~ActiveGame()
	{
	}

	weak_ptr<ChessPlayer> ActiveGame::GetActivePlayer() const
	{
		return weak_ptr<ChessPlayer>(_activePlayer);
	}

	bool ActiveGame::TryMakeMove(const GamePosition & from, const GamePosition & end)
	{
		if (_isGameEnded)
			return false;

		const ActiveGamePosition& activeGamePosition = _gameBoard->GetPosition(from);

		return false;
	}

	bool ActiveGame::IsGameEnded()
	{
		return _isGameEnded;
	}
}
