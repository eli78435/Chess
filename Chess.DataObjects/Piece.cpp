#include "Piece.h"

namespace Chess::DataObjects
{
	char GetChessPieceTypeRepresentation(ChessPieceType chessColor)
	{
		if (chessColor == ChessPieceType::King)
			return 'k';
		else if (chessColor == ChessPieceType::Queen)
			return 'q';
		else if (chessColor == ChessPieceType::Rook)
			return 'r';
		else if (chessColor == ChessPieceType::Bishop)
			return 'b';
		else if (chessColor == ChessPieceType::Nnight)
			return 'n';
		else
			return 'p';
	}

	char GetPlayerColorRepresentation(PlayerColor playerColor)
	{
		if (playerColor == PlayerColor::Black)
			return 'b';

		return 'w';
	}

	GameBoardPiece::GameBoardPiece()
	{
	}

	GameBoardPiece::GameBoardPiece(ChessPieceType chessPies, PlayerColor color) : _pieceType(chessPies), _pieceColor(color)
	{
	}

	GameBoardPiece::~GameBoardPiece()
	{
	}

	ChessPieceType GameBoardPiece::GetPieceType() const
	{
		return _pieceType;
	}

	PlayerColor GameBoardPiece::GetColorType() const
	{
		return _pieceColor;
	}

	const std::string* GameBoardPiece::ToString()
	{
		if (_toString == nullptr)
		{
			std::string colorAsString = _pieceColor == PlayerColor::Black ? "Black" : "White";
			std::string pieceAsString = _pieceType == ChessPieceType::King
				? "King"
				: _pieceType == ChessPieceType::Queen
				? "Queen"
				: _pieceType == ChessPieceType::Rook
				? "Rook"
				: _pieceType == ChessPieceType::Bishop
				? "Bishop"
				: _pieceType == ChessPieceType::Nnight
				? "Night"
				: "Pawn";

			_toString = new std::string(colorAsString + " " + pieceAsString);
		}

		return _toString;
	}
}
