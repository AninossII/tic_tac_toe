#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "BoardSquare.h"
#include "Board.h"
#include "IRuleEngine.h"

using namespace std;

class Game
{
	Board& _board;
	IRuleEngine& _ruleEngine;
public:
	Game(Board& board, IRuleEngine& ruleEngine);
	WinningPlayer::E Run();
	
private:
	void Render();
	char GetSquareChar(int index, BoardSquare::E square);
};

#endif
