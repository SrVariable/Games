#include "../include/tictactoe.h"

int	main(void)
{
	t_utils	*utils;

	utils = (t_utils *)malloc(sizeof(t_utils));
	utils->board = initialize_board(utils);
	if (utils->board == NULL)
	{
		return (0);
	}
	display_board(utils->board);
	full_free(utils, ROWS);
	return (0);
}
