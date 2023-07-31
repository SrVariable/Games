#ifndef TICTACTOE_H
# define TICTACTOE_H

/* <---Defines Section---> */
# define COLS 3
# define ROWS 3

/* <---Libraries Section---> */
# include <unistd.h>
# include <stdlib.h>

/* <--Structs Section-->*/
typedef struct s_utils
{
	char	player, symbol;
	char	**board;
	int		game, xpos, ypos;
}				t_utils;

/* <---Functions Section---> */
char	**initialize_board(t_utils *utils);
void	display_board(char **board);
void	full_free(t_utils *utils, int index);

#endif
