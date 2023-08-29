#ifndef CHESS_H
# define CHESS_H

/* <--Defines Section--> */
# define ROWS 40
# define COLS 40
# define MOVE_LENGTH 6

/* <--Libraries Section--> */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

/* <--Functions Section--> */
// Board
char	**create_board(void);
char	**initialize_board(void);
void	print_board(char **table);

// Piece
char	**put_pieces(char **table);
char	**move_piece(char **table);

// Other
bool	valid_move(char *movement);
int		parse_movement(char *movement);
void	full_free(char **table, int index);

#endif

