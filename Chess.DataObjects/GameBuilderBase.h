#pragma once

#include <memory>
#include "GameBoard.h"
#include "ChessPlayer.h"
#include "ActiveGame.h"

using namespace std;

namespace Chess::DataObjects
{
	class GameBuilderBase
	{
		shared_ptr<GameBoard> _gameBoard;
		shared_ptr<ChessPlayer> _whitePlayer;
		shared_ptr<ChessPlayer> _blackPlayer;

	protected:
		inline shared_ptr<GameBoard> GetGameBoard() const { return _gameBoard; }
		inline shared_ptr<ChessPlayer> GetWhitePlayer() const { return _whitePlayer; }
		inline shared_ptr<ChessPlayer> GetBlackPlayer() const { return _blackPlayer; }

		inline virtual shared_ptr<ChessPlayer> CreateWhitePlayer() { return nullptr; }
		inline virtual shared_ptr<ChessPlayer> CreateBlackPlayer() { return nullptr; }

	public:
		GameBuilderBase();
		~GameBuilderBase();

		const GameBuilderBase* InitializeBoard();
		const GameBuilderBase* BuildPlayers();
		virtual shared_ptr<ActiveGame> Build() abstract;
	};

	/*class AutonomousGameBuilder : public GameBuilderBase
	{
	public:
		AutonomousGameBuilder();
		~AutonomousGameBuilder();

		void StartPlay();
	};*/

	class TwoHumanGameBuilder : public GameBuilderBase
	{
	protected:
		virtual shared_ptr<ChessPlayer> CreateWhitePlayer();
		virtual shared_ptr<ChessPlayer> CreateBlackPlayer();
		
	public:
		TwoHumanGameBuilder();
		virtual shared_ptr<ActiveGame> Build();
	};
}

