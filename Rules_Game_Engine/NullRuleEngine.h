#pragma once
#ifndef NULLRULEENGINE_H
#define NULLRULEENGINE_H

#include <iostream>
#include "IRuleEngine.h"

using namespace std;

class NullRuleEngine : public IRuleEngine
{
	int GetIndexForXY(int x, int y, int width);
public:
	NullRuleEngine(Board& board);

	virtual WinningPlayer::E GetWinningPlayer(Board& board);
	
};

#endif
