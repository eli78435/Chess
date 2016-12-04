#include "Piece.h"

Piece::Piece(ChessPiece chessPies, PlayerColor color) : _chessPies(chessPies), _color(color)
{
}

Piece::~Piece()
{
}

const std::string* Piece::ToString()
{
	if (_toString == nullptr)
	{
		std::string colorAsString = _color == PlayerColor::Black ? "Black"s : "White"s;
		std::string pieceAsString = _chessPies == ChessPiece::King
			? "King"
			: _chessPies == ChessPiece::Queen
				? "Queen"
				: _chessPies == ChessPiece::Rook
					? "Rook"
					: _chessPies == ChessPiece::Bishop
						? "Bishop"
						: _chessPies == ChessPiece::Nnight
							? "Night"
							: "Pawn";

		_toString = new std::string(colorAsString + " " + pieceAsString);
	}

	return _toString;
}

void main()
{
	auto toString = BlackKing.ToString();
}
