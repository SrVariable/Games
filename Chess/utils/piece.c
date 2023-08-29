#include "../include/chess.h"

char	**put_pieces(char **table)
{
	char	*black;
	char	*white;
	int		index;

	black = "rnbqkbnrpppppppp";
	white = "RNBQKBNRPPPPPPPP";
	index = 0;
	for (int i = 2; i < ROWS / 4; i += 5)
	{
		for (int j = 2; j < COLS; j += 5)
		{
			table[i][j] = black[index];
			index++;
		}
	}
	for (int i = 32; i < ROWS; i += 5)
	{
		for (int j = 2; j < COLS; j += 5)
		{
			index--;
			table[i][j] = white[index];
		}
	}
	return (table);
}

char	**move_piece(char **table)
{
	char	*movement;

	movement = (char *)malloc((MOVE_LENGTH + 1) * sizeof(char));
	printf("Introduce your move: ");
	if (fgets(movement, MOVE_LENGTH + 1, stdin) == NULL)
	{
		fprintf(stderr, "Error movement\n");
		return (table);
	}
	if (parse_movement(movement) == 0)
	{
		printf("Invalid move\n");
		return (table);
	}
	return (table);
}
