#pragma once

#include <memory>
#include "Piece.h"
#include "GameBoard.h"

namespace Chess::DataObjects
{
	class ChessPlayer
	{
		PlayerColor _playerColor;
		weak_ptr<GameBoard> _gameBoard;
	
	protected:
		inline weak_ptr<GameBoard> GetGameBorder() const { return _gameBoard; }

	public:
		inline ChessPlayer(PlayerColor playerColor,  weak_ptr<GameBoard> gameBorder) : _playerColor(playerColor), _gameBoard(gameBorder) {};
		~ChessPlayer();

		inline PlayerColor GetColor() const { return _playerColor; };
		bool TryMove(GamePosition from, GamePosition to);
	};

	class HumanChessPlayer : public ChessPlayer
	{
	public:
		inline HumanChessPlayer(PlayerColor playerColor, weak_ptr<GameBoard> gameBorder) : ChessPlayer(playerColor, gameBorder) {};
	};

	/*class AutonomousChessPlayer : public ChessPlayer
	{
		bool MakeMove
	};*/
}

