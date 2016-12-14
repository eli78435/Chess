#pragma once

#include <memory>
#include "Piece.h"
#include "GameBoard.h"
#include "ChessPlayer.h"

namespace Chess::DataObjects
{
	class ActiveGame
	{
		shared_ptr<GameBoard> _gameBoard;
		shared_ptr<ChessPlayer> _whitePlayer;
		shared_ptr<ChessPlayer> _blackPlayer;

		shared_ptr<ChessPlayer> _activePlayer;

	public:
		ActiveGame(shared_ptr<GameBoard> gameBoard, shared_ptr<ChessPlayer> whitePlayer, shared_ptr<ChessPlayer> blackPlayer);
		~ActiveGame();

		weak_ptr<ChessPlayer> GetActivePlayer() const;
		bool TryMakeMove(GamePosition from, GamePosition end);
	};
}

