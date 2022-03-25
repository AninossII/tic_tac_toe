#include "Board.h"


Board::Board(int width) : _width(width)
{
	_squares = new BoardSquare::E[width * width];
	for (auto i = 0; i < GetTotalSquares(); i++)
	{
		_squares[i] = BoardSquare::E::Empty;
	}

}

Board::~Board()
{
	delete[] _squares;
}

int Board::GetWidth() { return _width; }
int Board::GetTotalSquares() { return _width * _width; }

BoardSquare::E Board::GetSquare(int index)
{
	return _squares[index];
}
void Board::SetSquare(int index, BoardSquare::E square)
{
	_squares[index] = square;
}