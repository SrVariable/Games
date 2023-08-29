#include "../include/chess.h"

bool	valid_move(char *movement)
{
	return (true);
}

int	parse_movement(char *movement)
{
	if (valid_move(movement) == true)
	{
		return (1);
	}
	return (0);
}

void	full_free(char **table, int index)
{
	while (index--)
	{
		free(table[index]);
	}
	free(table);
	return ;
}
