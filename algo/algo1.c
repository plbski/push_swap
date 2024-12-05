#include "../pushswap.h"

static void	log_swap(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	swap(stack);
}

static void	sort_three_continue(t_game *game, int *a)
{
	if (a[0] > a[1] && a[1] > a[2])
	{
		log_swap(game->lista, 'a');
		log_reverse_rotate(game->lista, 'a');
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		log_rotate(game->lista, 'a');
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		log_swap(game->lista, 'a');
		log_rotate(game->lista, 'a');
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		log_reverse_rotate(game->lista, 'a');
}

void	sort_three(t_game *game)
{
	int	*a;

	if (game->lista->size < 2)
		return ;
	a = game->lista->list;
	if (game->lista->size == 2)
	{
		if (a[0] > a[1])
			log_swap(game->lista, 'a');
		return ;
	}
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		log_swap(game->lista, 'a');
	else
		sort_three_continue(game, a);
}

static void	sort_stack_a(t_game *game)
{
	unsigned int	min_pos;
	unsigned int	i;

	i = 0;
	min_pos = 0;
	while (i < game->lista->size)
	{
		if (game->lista->list[i] < game->lista->list[min_pos])
			min_pos = i;
		i++;
	}
	if (min_pos <= game->lista->size / 2)
	{
		while (min_pos--)
			log_rotate(game->lista, 'a');
	}
	else
	{
		while (min_pos < game->lista->size)
		{
			log_reverse_rotate(game->lista, 'a');
			min_pos++;
		}
	}
}

void	turk_sort(t_game *game)
{
	if (game->lista->size <= 1)
		return ;
	if (game->lista->size == 2)
	{
		if (game->lista->list[0] > game->lista->list[1])
			log_swap(game->lista, 'a');
		return ;
	}
	while (game->lista->size > 3)
	{
		write(1, "pb\n", 3);
		pushb(game);
	}
	sort_three(game);
	while (game->listb->size > 0)
	{
		calculate_best_move(game);
		execute_rotation_both(game);
		execute_rotation(game->indmin->index_b, game->listb, 'b');
		execute_rotation(game->indmin->index_a, game->lista, 'a');
		write(1, "pa\n", 3);
		pusha(game);
	}
	sort_stack_a(game);
}
