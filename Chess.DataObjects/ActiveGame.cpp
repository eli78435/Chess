#include "ActiveGame.h"

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
}
