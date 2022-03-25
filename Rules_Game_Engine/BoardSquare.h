#pragma once
#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

struct BoardSquare
{
	enum E {
		X,
		O,
		Empty
	};
};

struct WinningPlayer
{
	enum E
	{
		X,
		O,
		Stalemate,
		None
	};
};

#endif
