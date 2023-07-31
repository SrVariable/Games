#include "../include/tictactoe.h"

char	**initialize_board(t_utils *utils)
{
	int		index, index2;

	index = 0;
	utils->board = (char **)malloc(ROWS * sizeof(char *));
	if (utils->board == NULL)
	{
		return (NULL);
	}
	while (index < ROWS)
	{
		utils->board[index] = (char *)malloc(COLS * sizeof(char));
		if (utils->board[index] == NULL)
		{
			full_free(utils, index);
			return (NULL);
		}
		index2 = 0;
		while (index2 < COLS)
		{
			if (index2 == COLS)
			{
				utils->board[index][index2] = '\0';
			}
			else
			{
				utils->board[index][index2] = ' ';
			}
			index2++;
		}
		index++;
	}
	utils->board[ROWS] = NULL;
	return (utils->board);
}

void	display_board(char **board)
{
	write (1, " ", 1); write(1, &board[0][0], 1); write(1, " | ", 3); write (1, &board[0][1], 1); write(1, " | ", 3); write(1, &board[0][2], 1); write(1, "\n", 1);
	write (1, "---+---+---\n", 13);
	write (1, " ", 1); write(1, &board[0][0], 1); write(1, " | ", 3); write (1, &board[1][1], 1); write(1, " | ", 3); write(1, &board[1][2], 1); write(1, "\n", 1);
	write (1, "---+---+---\n", 13);
	write (1, " ", 1); write(1, &board[0][0], 1); write(1, " | ", 3); write (1, &board[2][1], 1); write(1, " | ", 3); write(1, &board[2][2], 1); write(1, "\n", 1);
	return ;
}

void	full_free(t_utils *utils, int index)
{
	while (index)
	{
		free(utils->board[index]);
		index--;
	}
	free(utils->board);
	free(utils);
	return ;
}
