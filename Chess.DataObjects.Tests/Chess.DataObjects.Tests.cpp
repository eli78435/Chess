#pragma once 
#include "stdafx.h"

#ifndef  CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif // CATCH_CONFIG_MAIN 

#include "catch.hpp"
#include "..\\Chess.DataObjects\GameBoard.h"
#include "..\\Chess.DataObjects\Piece.h"

using namespace std;
using namespace Chess::DataObjects;

//TEST_CASE("Factorials are computed", "[factorial]") {
//	REQUIRE(Factorial(1) == 1);
//	REQUIRE(Factorial(2) == 2);
//	REQUIRE(Factorial(3) == 6);
//	REQUIRE(Factorial(10) == 3628800);
//}

//TEST_CASE("test 1") {
//	int negativeNumber = -1;
//	//REQUIRE(negativeNumber + 3 == 4);
//
//	SECTION("test 2")
//	{
//		negativeNumber = 3;
//		REQUIRE(negativeNumber == -1);
//	}
//
//
//	SECTION("test 2")
//	{
//		REQUIRE(negativeNumber == -1);
//
//	}
//}


TEST_CASE("GamePosition GetPosition, print it with ToString")
{
	GamePosition position{ 'a', 1 };
	auto toStringPtr = position.ToString();
	auto toString = *toStringPtr;
	
	REQUIRE(toString == "a1");
}

TEST_CASE("GameBoardPiece Get Position and Piece, print it with ToString")
{
	GamePosition position{ 'a', 1 };
	GameBoardPiece piece(ChessPieceType::King, PlayerColor::Black);

	ActiveGamePosition activePosition(position, piece);
	auto toStringPtr = activePosition.ToString();
	auto toString = *toStringPtr;

	REQUIRE(toString == "a1-kb");
}

