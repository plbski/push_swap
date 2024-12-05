#include "checker.h"

static int	init_stacks(t_game *game)
{
	if (alloc_stacks(game))
		return (1);
	if (alloc_lists(game))
		return (1);
	return (0);
}

static int	parse_numbers(t_game *game, char **temp, int curr_idx)
{
	unsigned int	i;
	long			num;

	i = 0;
	while (temp[i])
	{
		num = ft_atol(temp[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		game->lista->list[curr_idx + i] = (int)num;
		i++;
	}
	game->lista->size += i;
	return (0);
}

static int	count_and_validate(t_game *game)
{
	char	**temp;
	int		i;
	int		total;

	game->maxsize = 0;
	i = 1;
	while (i < game->ac)
	{
		temp = ft_split(game->av[i], ' ');
		if (!temp || checker_alpha(temp))
		{
			cleanup_split(temp);
			return (1);
		}
		total = countnum(temp);
		if (total == 0)
		{
			cleanup_split(temp);
			return (1);
		}
		game->maxsize += total;
		cleanup_split(temp);
		i++;
	}
	return (0);
}

static int	fill_numbers(t_game *game)
{
	char	**temp;
	int		i;
	int		curr_idx;

	curr_idx = 0;
	i = 1;
	while (i < game->ac)
	{
		temp = ft_split(game->av[i], ' ');
		if (parse_numbers(game, temp, curr_idx))
		{
			cleanup_split(temp);
			return (1);
		}
		curr_idx += countnum(temp);
		cleanup_split(temp);
		i++;
	}
	return (0);
}

int	checker_init(t_game *game)
{
	if (count_and_validate(game))
		return (1);
	if (init_stacks(game))
		return (1);
	if (fill_numbers(game))
	{
		cleanup_game(game);
		return (1);
	}
	if (checker_input(game->lista))
	{
		cleanup_game(game);
		return (1);
	}
	return (0);
}
