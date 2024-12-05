#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				*list;
	unsigned int	size;
}	t_stack;

typedef struct s_imin
{
	unsigned int	index_a;
	unsigned int	index_b;
	int				min;
	int				tmp_min;
}	t_imin;

typedef struct s_game
{
	int				ac;
	char			**av;
	t_stack			*lista;
	t_stack			*listb;
	unsigned int	costa;
	unsigned int	costb;
	unsigned int	maxsize;
	unsigned int	error;
	t_imin			*indmin;
}	t_game;

int		init(t_game *game);

// Operations
int		*rotstring(t_stack *pile);
int		*revrotstring(t_stack *pile);
int		*swap(t_stack *pile);
void	pusha(t_game *game);
void	pushb(t_game *game);
void	shift_down_a(t_game *game);
void	shift_down_b(t_game *game);

// Input_check
int		check_input(t_stack *lista);
int		check_alpha(char **temp);

//Utils
int		countnum(char **temp);
void	cleanup_split(char **temp);
void	cleanup_game(t_game *game);
int		init_lists(t_game *game);
long	check(long num, t_game *game);

//algo
// void calculate_minimal_cost(t_game *game);
void	calculate_best_move(t_game *game);
void	execute_rotation(unsigned int index, t_stack *stack, char stack_name);
void	sort_three(t_game *game);
void	turk_sort(t_game *game);

//best move
void	calculate_best_move(t_game *game);

//rotate
void	execute_rotation_both(t_game *game);
void	execute_rotation(unsigned int index, t_stack *stack, char stack_name);
void	log_reverse_rotate(t_stack *stack, char stack_name);
void	log_rotate(t_stack *stack, char stack_name);

#endif
