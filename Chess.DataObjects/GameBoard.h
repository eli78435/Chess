#pragma once
#include <string>
#include <map>
#include <memory>
#include "Piece.h"

using namespace std;

namespace Chess::DataObjects
{
	struct GamePosition
	{
		char CharCoordinate;
		int IntCoordinate;

		unique_ptr<std::string> ToString() const;
	};

	class ActiveGamePosition
	{
	private:
		GamePosition _position;
		GameBoardPiece _piece;

	public:
		ActiveGamePosition(GamePosition position, GameBoardPiece piece);
		unique_ptr<string> ToString() const;
	};

	class GameBoard
	{
	private:
		void InitializeBoard();
	public:
		GameBoard();
		~GameBoard();

		void Print();
	};
}

