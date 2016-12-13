#include "GameBoard.h"

using namespace std;

namespace Chess::DataObjects
{
	///////////////////////////////////////////
	//Game Postion
	///////////////////////////////////////////

	unique_ptr<string> GamePosition::ToString() const
	{
		auto str = make_unique<string>(string(1, CharCoordinate) + std::to_string(IntCoordinate));
		return str;
	}

	bool operator==(const GamePosition& lhs, const GamePosition& rhs)
	{
		return lhs.CharCoordinate == rhs.CharCoordinate && lhs.IntCoordinate == rhs.IntCoordinate;
	}

	///////////////////////////////////////////
	//Game Board
	///////////////////////////////////////////

	GameBoard::GameBoard()
	{
	}

	void GameBoard::InitializeBoard()
	{
		/*pair<GamePosition, ActiveGamePosition> pair(GamePosition{ 'a',1 }, 
													ActiveGamePosition(GamePosition{ 'a',1 }, WhiteRook));
		_picesOnBoard.insert(pair);*/

		_picesOnBoard[GamePosition{ 'a',1 }] = ActiveGamePosition(GamePosition{ 'a',1 }, WhiteRook);
	}


	GameBoard::~GameBoard()
	{
	}

	//ActiveGamePosition GameBoard::GetPosition(GamePosition position) const
	//{
	//	//return _picesOnBoard
	//}

	void GameBoard::Print()
	{
	}

	///////////////////////////////////////////
	//ActiveGamePosition
	///////////////////////////////////////////

	ActiveGamePosition::ActiveGamePosition()
	{
	}

	ActiveGamePosition::ActiveGamePosition(GamePosition position, GameBoardPiece piece)
		: _position(position), _piece(piece)
	{
	}

	unique_ptr<string> ActiveGamePosition::ToString() const
	{
		auto str = make_unique<string>(*_position.ToString() + 
			"-" + 
			string { 
				GetChessPieceTypeRepresentation(_piece.GetPieceType()), GetPlayerColorRepresentation(_piece.GetColorType())
			});
		return str;

		return make_unique<string>();
	}
}
