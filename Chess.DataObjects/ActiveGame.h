#pragma once

#include <memory>
#include "Piece.h"
#include "GameBoard.h"
#include "ChessPlayer.h"

namespace Chess::DataObjects
{
	class ActiveGame
	{
		bool _isGameEnded = false;

		std::shared_ptr<GameBoard> _gameBoard;
		std::shared_ptr<ChessPlayer> _whitePlayer;
		std::shared_ptr<ChessPlayer> _blackPlayer;

		std::shared_ptr<ChessPlayer> _activePlayer;

	public:
		ActiveGame(std::shared_ptr<GameBoard> gameBoard, std::shared_ptr<ChessPlayer> whitePlayer, std::shared_ptr<ChessPlayer> blackPlayer);
		~ActiveGame();

		std::weak_ptr<ChessPlayer> GetActivePlayer() const;
		bool TryMakeMove(const GamePosition& from, const GamePosition& end);
		bool IsGameEnded();
	};
}

