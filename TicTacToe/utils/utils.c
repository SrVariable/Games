#include "../include/tictactoe.h"

char	**initialize_board(t_game *game)
{
	int		index, index2;

	index = 0;
	game->board = (char **)malloc(ROWS * sizeof(char *));
	if (game->board == NULL)
	{
		full_free(game, index);
		return (NULL);
	}
	while (index < ROWS)
	{
		game->board[index] = (char *)malloc(COLS * sizeof(char));
		if (game->board[index] == NULL)
		{
			full_free(game, index);
			return (NULL);
		}
		index2 = 0;
		while (index2 < COLS)
		{
			if (index2 == COLS)
			{
				game->board[index][index2] = '\0';
			}
			else
			{
				game->board[index][index2] = ' ';
			}
			index2++;
		}
		index++;
	}
	game->board[index] = NULL;
	return (game->board);
}

void	display_board(char **board)
{
	write (1, "\n ", 2); write(1, &board[0][0], 1); write(1, " | ", 3); write (1, &board[0][1], 1); write(1, " | ", 3); write(1, &board[0][2], 1); write(1, "\n", 1);
	write (1, "---+---+---\n", 13);
	write (1, " ", 1); write(1, &board[1][0], 1); write(1, " | ", 3); write (1, &board[1][1], 1); write(1, " | ", 3); write(1, &board[1][2], 1); write(1, "\n", 1);
	write (1, "---+---+---\n", 13);
	write (1, " ", 1); write(1, &board[2][0], 1); write(1, " | ", 3); write (1, &board[2][1], 1); write(1, " | ", 3); write(1, &board[2][2], 1); write(1, "\n", 1);
	return ;
}
