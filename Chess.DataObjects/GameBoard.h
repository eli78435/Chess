#pragma once
#include <string>
#include <unordered_map>
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

	bool operator==(const GamePosition& lhs, const GamePosition& rhs);
}

namespace std
{
	template<>
	struct hash<Chess::DataObjects::GamePosition>
	{
		std::size_t operator()(const Chess::DataObjects::GamePosition& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			return hash<char>()(k.CharCoordinate) ^ hash<int>()(k.IntCoordinate);
		}
	};
}

namespace Chess::DataObjects
{
	class ActiveGamePosition
	{
	private:
		GamePosition _position;
		GameBoardPiece _piece;

	public:
		ActiveGamePosition();
		ActiveGamePosition(GamePosition position, GameBoardPiece piece);
		unique_ptr<string> ToString() const;
	};

	class GameBoard
	{
	private:
		unordered_map<GamePosition, ActiveGamePosition> _picesOnBoard;
		
	public:
		GameBoard();
		void InitializeBoard();
		~GameBoard();

		ActiveGamePosition GetPosition(GamePosition position) const;

		void Print();
	};
}

