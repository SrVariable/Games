#include "../include/chess.h"

char	**create_board(void)
{
	bool	isBlack;
	char	**table;

	isBlack = false;
	table = (char **)malloc((ROWS + 1) * sizeof(char *));
	if (table == NULL)
	{
		return (NULL);
	}
	for (int i = 0; i < ROWS; i++)
	{
		table[i] = (char *)malloc((COLS + 1) * sizeof(char));
		if (table[i] == NULL)
		{
			full_free(table, i);
			return (NULL);
		}
		if (i % 5 == 0)
		{
			isBlack = !isBlack;
		}
		for (int j = 0; j < COLS; j++)
		{
			if (j % 5 == 0)
			{
				isBlack = !isBlack;
			}
			if (isBlack == true)
			{
				table[i][j] = '-';
			}
			else
			{
				table[i][j] = ' ';
			}
		}
		table[i][COLS] = '\0';
	}
	table[ROWS] = NULL;
	return (table);
}

char	**initialize_board(void)
{
	char	**table;

	table = create_board();
	if (table == NULL)
	{
		return (NULL);
	}
	table = put_pieces(table);
	return (table);
}

void	print_board(char **table)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c", table[i][j]);
		}
		printf("\n");
	}
	return ;
}
