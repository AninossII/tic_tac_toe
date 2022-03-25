#pragma once
#ifndef IRULEENGINE_H
#define IRULEENGINE_H

#include "Board.h"

class IRuleEngine
{
public:
	virtual WinningPlayer::E GetWinningPlayer(Board& board) = 0;

};

#endif
