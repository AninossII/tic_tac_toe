#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "BoardSquare.h"

class Board
{
private:
	int _width;
	BoardSquare::E* _squares;
public:

	Board(int width);
	~Board();

	int GetWidth();
	int GetTotalSquares();

	BoardSquare::E GetSquare(int index);
	void SetSquare(int index, BoardSquare::E square);
};

#endif
