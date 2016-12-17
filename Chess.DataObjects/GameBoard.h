#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "Piece.h"

#define CHAR_TO_DIGIT(c) (c-'0')

namespace Chess::DataObjects
{
	class GamePositionValidity
	{
	public:
		static bool IsFirstPositionValid(char position);
		static bool IsFSecondPositionValid(int position);
	};

	struct GamePosition
	{
		char CharCoordinate;
		int IntCoordinate;

		std::unique_ptr<std::string> ToString() const;
	};

	bool operator==(const GamePosition& lhs, const GamePosition& rhs);
	bool operator!=(const GamePosition& lhs, const GamePosition& rhs);
	bool TryParse(const std::string & text, GamePosition & gamePosition);
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
		~ActiveGamePosition();
		std::unique_ptr<std::string> ToString() const;
	};

	class GameBoard
	{
	private:
		std::unordered_map<GamePosition, ActiveGamePosition> _picesOnBoard;
		
	public:
		GameBoard();
		void InitializeBoard();
		~GameBoard();

		const ActiveGamePosition& GetPosition(const GamePosition& position) const;

		void Print();
	};
}

