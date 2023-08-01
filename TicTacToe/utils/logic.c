#include "../include/tictactoe.h"

int	valid_move(int xpos, int ypos)
{
	return (xpos > 0 && xpos <= ROWS && ypos > 0 && ypos <= COLS);
}

int	check_win(char **board, char symbol)
{
	if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) ||
		(board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
		(board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol))
	{
		return (1);
	}
	else if ((board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) ||
			(board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
			(board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol))
	{
		return (1);
	}
	else if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
			(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
	{
		return (1);
	}
	return (0);
}

int	board_full(char **board)
{
	int	index, index2, counter;

	index = 0;
	counter = 0;
	while (index < ROWS)
	{
		index2 = 0;
		while (index2 < COLS)
		{
			if (board[index][index2] == ' ')
			{
				counter++;
			}
			index2++;
		}
		index++;
	}
	if (counter == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	full_free(t_game *game, int index)
{
	while (index)
	{
		free(game->board[index]);
		index--;
	}
	if (game->board != NULL)
	{
		free(game->board);
	}
	free(game);
	return ;
}
