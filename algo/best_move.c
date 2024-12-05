#include "../pushswap.h"

static int	get_target_position_biggest(t_game *game, unsigned int i)
{
	int	closest_bigger;
	int	target_pos;

	target_pos = 0;
	closest_bigger = 2147483647;
	while (i < game->lista->size)
	{
		if (game->lista->list[i] < closest_bigger)
		{
			closest_bigger = game->lista->list[i];
			target_pos = i;
		}
		i++;
	}
	return (target_pos);
}

static int	get_target_position(t_game *game, int value)
{
	unsigned int	i;
	int				target_pos;
	int				closest_bigger;

	closest_bigger = 2147483647;
	target_pos = 0;
	i = 0;
	while (i < game->lista->size)
	{
		if (game->lista->list[i] > value
			&& game->lista->list[i] < closest_bigger)
		{
			closest_bigger = game->lista->list[i];
			target_pos = i;
		}
		i++;
	}
	if (closest_bigger == 2147483647)
		target_pos = get_target_position_biggest(game, 0);
	return (target_pos);
}

static int	get_total_cost(t_game *game, unsigned int i, unsigned int j)
{
	unsigned int	costa;
	unsigned int	costb;

	if (j <= game->lista->size / 2)
		costa = j;
	else
		costa = game->lista->size - j;
	if (i <= game->listb->size / 2)
		costb = i;
	else
		costb = game->listb->size - i;
	if ((j <= game->lista->size / 2 && i <= game->listb->size / 2)
		|| (j > game->lista->size / 2 && i > game->listb->size / 2))
	{
		if (costa > costb)
			return (costa);
		else
			return (costb);
	}
	return (costa + costb);
}

void	calculate_best_move(t_game *game)
{
	unsigned int	i;
	unsigned int	j;
	int				total_cost;

	game->indmin->min = 2147483647;
	i = 0;
	while (i < game->listb->size)
	{
		j = get_target_position(game, game->listb->list[i]);
		total_cost = get_total_cost(game, i, j);
		if (total_cost < game->indmin->min)
		{
			game->indmin->min = total_cost;
			game->indmin->index_a = j;
			game->indmin->index_b = i;
		}
		i++;
	}
}
