#include "GameBuilderBase.h"

namespace Chess::DataObjects
{

	GameBuilderBase::GameBuilderBase()
	{
		_gameBoard = make_shared<GameBoard>();
	}


	GameBuilderBase::~GameBuilderBase()
	{
	}

	const GameBuilderBase* GameBuilderBase::InitializeBoard()
	{
		_gameBoard->InitializeBoard();

		return this;
	}

	const GameBuilderBase* GameBuilderBase::BuildPlayers()
	{
		_whitePlayer = CreateWhitePlayer();
		_blackPlayer = CreateBlackPlayer();

		return this;
	}

	inline shared_ptr<ChessPlayer> TwoHumanGameBuilder::CreateWhitePlayer()
	{
		auto gameBoard = GetGameBoard();
		weak_ptr<GameBoard> weakGameBoardRef = gameBoard;

		//auto whitePlayer = new ChessPlayer(PlayerColor::White, weakGameBoardRef);

		return make_shared<ChessPlayer>(PlayerColor::White, weakGameBoardRef);
	}

	inline shared_ptr<ChessPlayer> TwoHumanGameBuilder::CreateBlackPlayer()
	{
		auto gameBoard = GetGameBoard();
		weak_ptr<GameBoard> weakGameBoardRef = gameBoard;

		//auto blackPlayer = new ChessPlayer(PlayerColor::Black, weakGameBoardRef);

		return make_shared<ChessPlayer>(PlayerColor::Black, weakGameBoardRef);
	}

	shared_ptr<ActiveGame> TwoHumanGameBuilder::Build()
	{
		return make_shared<ActiveGame>(GetGameBoard(), GetWhitePlayer(), GetBlackPlayer());
	}

	TwoHumanGameBuilder::TwoHumanGameBuilder()
	{
	}
}
