#ifndef TICTACTOE_H
# define TICTACTOE_H

/* <---Defines Section---> */
# define COLS 3
# define ROWS 3

/* <---Libraries Section---> */
# include <unistd.h>
# include <stdlib.h>

/* <--Structs Section-->*/
typedef struct s_game
{
	char	remove_newline, xpos, ypos;
	char	symbol[2];
	char	**board;
	int		end, player;
}				t_game;

/* <---Functions Section---> */
char	**initialize_board(t_game *utils);
void	display_board(char **board);
void	full_free(t_game *utils, int index);
int		valid_move(int xpos, int ypos);
int		check_win(char **board, char symbol);
int		board_full(char **board);

#endif
