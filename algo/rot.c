#include "../pushswap.h"

void	execute_rotation_both(t_game *game)
{
	unsigned int	*index_a;
	unsigned int	*index_b;

	index_a = &game->indmin->index_a;
	index_b = &game->indmin->index_b;
	while (*index_a > 0 && *index_a <= game->lista->size / 2
		&& *index_b > 0 && *index_b <= game->listb->size / 2)
	{
		write(1, "rr\n", 3);
		rotstring(game->lista);
		rotstring(game->listb);
		(*index_a)--;
		(*index_b)--;
	}
	while (*index_a > game->lista->size / 2
		&& *index_b > game->listb->size / 2
		&& *index_a < game->lista->size
		&& *index_b < game->listb->size)
	{
		write(1, "rrr\n", 4);
		revrotstring(game->lista);
		revrotstring(game->listb);
		(*index_a)++;
		(*index_b)++;
	}
}

void	log_rotate(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	rotstring(stack);
}

void	log_reverse_rotate(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	revrotstring(stack);
}

void	execute_rotation(unsigned int index, t_stack *stack, char stack_name)
{
	unsigned int	mid;

	mid = stack->size / 2;
	if (index <= mid)
	{
		while (index > 0)
		{
			log_rotate(stack, stack_name);
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			log_reverse_rotate(stack, stack_name);
			(index)++;
		}
	}
}
