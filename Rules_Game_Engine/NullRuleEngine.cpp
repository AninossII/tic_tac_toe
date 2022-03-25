#include "NullRuleEngine.h"

NullRuleEngine::NullRuleEngine(Board& board)
{	
}

int NullRuleEngine::GetIndexForXY(int x, int y, int width)
{
	return width * y + x;
}

WinningPlayer::E NullRuleEngine::GetWinningPlayer(Board& board)
{
	
	// End the game
	bool foundAnyEmpty = false;
	for(unsigned int i = 0; i < board.GetTotalSquares(); i++)
	{
		if(board.GetSquare(i) == BoardSquare::Empty)
		{
			foundAnyEmpty = true;
			break;
		}		
	}
	if (!foundAnyEmpty)
	{		
		return WinningPlayer::Stalemate;
	}

	// Horizontal Rows
	for(unsigned int y =0; y < board.GetWidth(); y++)
	{
		BoardSquare::E allOfTypes;

		int firstRow = GetIndexForXY(0, y, board.GetWidth());
		allOfTypes = board.GetSquare(firstRow);
		if(allOfTypes == BoardSquare::Empty)
		{
			continue;
		}

		WinningPlayer::E winningPlayer = allOfTypes == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

		
		for(unsigned int x = 1; x < board.GetWidth(); x++)
		{
			if (allOfTypes != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
			{
				winningPlayer = WinningPlayer::None;
				break;
			}
				
		}

		// Check Winning
		if(winningPlayer != WinningPlayer::None)
		{
			return winningPlayer;
		}
	}

	// Vertical Rows
	for (unsigned int x = 0; x < board.GetWidth(); x++)
	{
		BoardSquare::E allOfTypes;

		int firstRow = GetIndexForXY(x, 0, board.GetWidth());
		allOfTypes = board.GetSquare(firstRow);
		if (allOfTypes == BoardSquare::Empty)
		{
			continue;
		}

		WinningPlayer::E winningPlayer = allOfTypes == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

		for (unsigned int y = 1; y < board.GetWidth(); y++)
		{
			if (allOfTypes != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
			{				
				winningPlayer = WinningPlayer::None;
				break;
			}
		}

		// Check Winning
		if (winningPlayer != WinningPlayer::None)
		{
			return winningPlayer;
		}
	}

	// Diagonal Rows From 1 to 9
	BoardSquare::E allOfTypes = board.GetSquare(GetIndexForXY(0, 0, board.GetWidth()));
	if (allOfTypes != BoardSquare::Empty)
	{
		WinningPlayer::E winningPlayer = allOfTypes == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;
		for (unsigned int x = 1; x < board.GetWidth(); x++)
		{
			for (unsigned int y = 1; y < board.GetWidth(); y++)
			{				
				if(x != y)								
					continue;
				
				if (allOfTypes != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
				{
					winningPlayer = WinningPlayer::None;
					break;
				}
			}
			if (winningPlayer == WinningPlayer::None)
				break;
			
		}

		// Check Winning
		if (winningPlayer != WinningPlayer::None)
		{
			return winningPlayer;
		}
	}

	// Diagonal Rows From 3 to 7
	allOfTypes = board.GetSquare(GetIndexForXY(board.GetWidth() - 1, 0, board.GetWidth()));
	if(allOfTypes != BoardSquare::Empty)
	{
		WinningPlayer::E winningPlayer = allOfTypes == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;
		for (int x = board.GetWidth() - 2; x >= 0; x--)
		{			
			for (unsigned int y = 1; y < board.GetWidth(); y++)
			{				
				if ( board.GetWidth() - 1 -x != y)
					continue;

				if (allOfTypes != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
				{
					winningPlayer = WinningPlayer::None;
					break;
				}
			}

			if (winningPlayer == WinningPlayer::None)
				break;
		}

		// Check Winning
		if (winningPlayer != WinningPlayer::None)
			return winningPlayer;
	}

	return WinningPlayer::E::None;
}