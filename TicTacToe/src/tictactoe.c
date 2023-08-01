#include "../include/tictactoe.h"

int	main(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->board = initialize_board(game);
	if (game->board == NULL)
	{
		return (0);
	}
	game->end = 0;
	write(1, "Elige tu símbolo [x-o]: ", 26);
	while (game->symbol[0] != 'x' && game->symbol[0] != 'o')
	{
		if (read(0, &game->symbol[0], 1) < 0)
		{
			full_free(game, ROWS);
			return (0);
		}
	}
	if (read(0, &game->remove_newline, 1) < 0)
	{
		full_free(game, ROWS);
		return (0);
	}
	game->player = 1;
	write(1, "\nDe acuerdo, tu símbolo será ", 31); write(1, &game->symbol[0], 1);
	if (game->symbol[0] == 'x')
	{
		game->symbol[1] = 'o';
		write(1, "\nEl jugador 2 usará el símbolo o\n", 35);
	}
	else if (game->symbol[0] == 'o')
	{
		game->symbol[1] = 'x';
		write(1, "\nEl jugador 2 usará el símbolo x\n", 35);
	}
	while (!game->end)
	{
		if (game->player == 1)
		{
			write(1, "\nTurno del jugador 1\n", 21);
		}
		else
		{
			write(1, "\nTurno del jugador 2\n", 21);
		}
		write(1, "Introduce la posición de la fila: ", 36);
		if (read(0, &game->xpos, 1) < 0)
		{
			full_free(game, ROWS);
			return (0);
		}
		if (read(0, &game->remove_newline, 1) < 0)
		{
			full_free(game, ROWS);
			return (0);
		}
		write(1, "Introduce la posición de la columna: ", 39);
		if (read(0, &game->ypos, 1) < 0)
		{
			full_free(game, ROWS);
			return (0);
		}
		if (read(0, &game->remove_newline, 1) < 0)
		{
			full_free(game, ROWS);
			return (0);
		}
		if (valid_move(game->xpos - '0', game->ypos -'0') == 1)
		{
			if (game->board[game->xpos - '0' - 1][game->ypos - '0' - 1] == ' ')
			{
				if (game->player == 1)
				{
					game->board[game->xpos - '0' - 1][game->ypos - '0' - 1] = game->symbol[0];
				}
				else
				{
					game->board[game->xpos - '0' - 1][game->ypos - '0' - 1] = game->symbol[1];
				}
				game->player = !game->player;
				display_board(game->board);
			}
			else
			{
				write(1, "\nYa hay una pieza\n", 18);
			}
		}
		else
		{
			write(1, "\nPosición inválida\n", 22);
		}
		if (check_win(game->board, 'x') == 1)
		{
			if (game->symbol[0] == 'x')
			{
				write(1, "Has ganado\n", 11);
			}
			else
			{
				write(1, "Has perdido\n", 12);
			}
			game->end = 1;
		}
		else if (check_win(game->board, 'o')== 1)
		{
			if (game->symbol[0] == 'o')
			{
				write(1, "Has ganado\n", 11);
			}
			else
			{
				write(1, "Has perdido\n", 12);
			}
			game->end = 1;
		}
		else if (board_full(game->board) == 1)
		{
			write(1, "Empate\n", 7);
			game->end = 1;
		}
	}
	full_free(game, ROWS);
	return (0);
}
