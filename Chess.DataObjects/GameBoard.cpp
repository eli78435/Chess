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

	///////////////////////////////////////////
	//Game Board
	///////////////////////////////////////////

	GameBoard::GameBoard()
	{
	}


	GameBoard::~GameBoard()
	{
	}

	void GameBoard::Print()
	{
	}

	///////////////////////////////////////////
	//ActiveGamePosition
	///////////////////////////////////////////

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
