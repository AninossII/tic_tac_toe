#include "Board.h"
#include "NullRuleEngine.h"
#include "Game.h"



int main()
{
	Board board(3);
	NullRuleEngine ruleEngine(board);

	Game game(board, ruleEngine);
	game.Run();

	return 0;
}