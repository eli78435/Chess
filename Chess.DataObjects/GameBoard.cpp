#include "GameBoard.h"

using namespace std;

namespace Chess::DataObjects
{
	///////////////////////////////////////////
	//GamePositionValidity
	///////////////////////////////////////////

	inline bool GamePositionValidity::IsFirstPositionValid(char position)
	{
		if ('a' <= position <= 'h')
			return true;

		return false;
	}

	inline bool GamePositionValidity::IsFSecondPositionValid(int position)
	{
		if (1 <= position <= 8)
			return true;

		return false;
	}


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

	bool operator!=(const GamePosition & lhs, const GamePosition & rhs)
	{
		return lhs.CharCoordinate != rhs.CharCoordinate || lhs.IntCoordinate != rhs.IntCoordinate;
	}

	static bool TryParse(const string& text, GamePosition & gamePosition)
	{
		if (text.length() != 2)
			return false;

		char firstLetter = text[0];
		if (GamePositionValidity::IsFirstPositionValid(firstLetter))
		{
			char secondChar = text[1];
			int secondNumber = CHAR_TO_DIGIT(secondChar);

			if (GamePositionValidity::IsFSecondPositionValid(secondNumber))
			{
				gamePosition.CharCoordinate = firstLetter;
				gamePosition.IntCoordinate = secondNumber;

				return true;
			}
		}

		return false;
	}

	///////////////////////////////////////////
	//Game Board
	///////////////////////////////////////////

	GameBoard::GameBoard()
	{
	}

	void GameBoard::InitializeBoard()
	{
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
