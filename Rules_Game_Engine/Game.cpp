#include "Game.h"

Game::Game(Board& board, IRuleEngine& ruleEngine) : _board(board), _ruleEngine(ruleEngine)
{
}

WinningPlayer::E Game::Run()
{
	WinningPlayer::E winningPlayer, currentPlayer = WinningPlayer::E::X;
	while ((winningPlayer = _ruleEngine.GetWinningPlayer(_board)) == WinningPlayer::E::None)
	{
		Render();
		std::cout << "\n";

		int input;
		cout << "Move for " << (currentPlayer == WinningPlayer::X ? 'X' : 'O') << ": ";
		cin >> input;
		cin.ignore();		
		cin.clear();
		
		input -= 1;
		if (input < 0 || input > _board.GetTotalSquares() || _board.GetSquare(input) != BoardSquare::E::Empty)
		{
			std::cout << "Invalid Move! \n";
			continue;			

		}
		
		_board.SetSquare(input, currentPlayer == WinningPlayer::X ? BoardSquare::E::X : BoardSquare::E::O);
		currentPlayer = currentPlayer == WinningPlayer::E::X ? WinningPlayer::E::O : WinningPlayer::E::X;
	}
	return winningPlayer;
}

void Game::Render()
{
	// Clean the Console
	//system("cls");

	cout << "===============" << endl;
	for (auto i = 1; i <= _board.GetTotalSquares(); i++)
	{		
		cout << "| " << GetSquareChar(i, _board.GetSquare(i - 1)) << " |";
		if ((i % _board.GetWidth()) == 0)
		{
			cout << "\n";
			cout << "===============" << endl;
		}
	}
}

char Game::GetSquareChar(int index, BoardSquare::E square)
{
	switch (square)
	{
	case BoardSquare::E::X: return 'X';
	case BoardSquare::E::O: return 'O';
	}

	return index + '0';
}