#pragma once

#include <iostream>
#include <string>

using namespace std;

enum class ChessPiece {
	King = 0,
	Queen = 1,
	Rook = 2,
	Bishop = 3,
	Nnight = 4,
	Pawn = 5
};

enum class PlayerColor {Black = 0, White = 1 };

class Piece
{
private:
	ChessPiece _chessPies;
	PlayerColor _color;

	std::string* _toString;
public:
	Piece(ChessPiece chessPies, PlayerColor color);
	~Piece();

	const std::string* ToString();
};

static Piece BlackKing(ChessPiece::King, PlayerColor::Black);

