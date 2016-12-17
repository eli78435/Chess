#pragma once

#include <memory>
#include "GameBoard.h"
#include "ChessPlayer.h"
#include "ActiveGame.h"

namespace Chess::DataObjects
{
	class GameBuilderBase
	{
		std::shared_ptr<GameBoard> _gameBoard;
		std::shared_ptr<ChessPlayer> _whitePlayer;
		std::shared_ptr<ChessPlayer> _blackPlayer;

	protected:
		inline std::shared_ptr<GameBoard> GetGameBoard() const { return _gameBoard; }
		inline std::shared_ptr<ChessPlayer> GetWhitePlayer() const { return _whitePlayer; }
		inline std::shared_ptr<ChessPlayer> GetBlackPlayer() const { return _blackPlayer; }

		inline virtual std::shared_ptr<ChessPlayer> CreateWhitePlayer() { return nullptr; }
		inline virtual std::shared_ptr<ChessPlayer> CreateBlackPlayer() { return nullptr; }

	public:
		GameBuilderBase();
		~GameBuilderBase();

		const GameBuilderBase* InitializeBoard();
		const GameBuilderBase* BuildPlayers();
		virtual std::shared_ptr<ActiveGame> Build() abstract;
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
		virtual std::shared_ptr<ChessPlayer> CreateWhitePlayer();
		virtual std::shared_ptr<ChessPlayer> CreateBlackPlayer();
		
	public:
		TwoHumanGameBuilder();
		virtual std::shared_ptr<ActiveGame> Build();
	};
}

