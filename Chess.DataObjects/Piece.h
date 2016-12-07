#pragma once

#include <iostream>
#include <string>

namespace Chess::DataObjects
{
	enum class ChessPieceType {
		King = 0,
		Queen = 1,
		Rook = 2,
		Bishop = 3,
		Nnight = 4,
		Pawn = 5
	};

	char GetChessPieceTypeRepresentation(ChessPieceType);

	enum class PlayerColor { Black = 0, White = 1 };

	char GetPlayerColorRepresentation(PlayerColor);

	class GameBoardPiece
	{
	private:
		ChessPieceType _pieceType;
		PlayerColor _pieceColor;

		std::string* _toString;
	public:
		GameBoardPiece(ChessPieceType chessPies, PlayerColor color);
		~GameBoardPiece();

		ChessPieceType GetPieceType() const;
		PlayerColor GetColorType() const;

		const std::string* ToString();
	};

	static GameBoardPiece BlackKing(ChessPieceType::King, PlayerColor::Black);
}

