#include "../include/chess.h"


int	main(void)
{
	char	**table;

	table = initialize_board();
	if (table == NULL)
	{
		fprintf(stderr, "Error malloc\n");
		return (1);
	}
	print_board(table);
	table = move_piece(table);
	full_free(table, ROWS);
	return (0);
}
