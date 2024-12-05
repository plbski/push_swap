#include "pushswap.h"

static void	fill_lists_from_args(t_game *game)
{
	unsigned int	i;
	long			num;

	num = 0;
	i = 1;
	while (i <= game->maxsize)
	{
		num = check(ft_atol(game->av[i]), game);
		game->lista->list[i - 1] = (int)num;
		game->listb->list[i - 1] = 0;
		i++;
	}
	game->lista->size = game->maxsize;
	game->listb->size = 0;
}

static void	fill_lists_from_split(t_game *game, char **temp)
{
	unsigned int	i;
	long			num;

	i = 0;
	num = 0;
	while (i < game->maxsize)
	{
		num = check(ft_atol(temp[i]), game);
		game->error += check_alpha(temp);
		game->lista->list[i] = (int)num;
		game->listb->list[i] = 0;
		i++;
	}
	game->lista->size = game->maxsize;
	game->listb->size = 0;
}

static int	handle_split_input(t_game *game)
{
	char	**temp;

	temp = ft_split(game->av[1], ' ');
	if (!temp)
		return (0);
	game->maxsize = countnum(temp);
	if (game->maxsize == 0)
	{
		cleanup_split(temp);
		return (0);
	}
	if (!init_lists(game))
	{
		cleanup_split(temp);
		return (0);
	}
	fill_lists_from_split(game, temp);
	cleanup_split(temp);
	return (1);
}

static void	init_stacks(t_game *game)
{
	game->lista->list = NULL;
	game->lista->size = 0;
	game->listb->list = NULL;
	game->listb->size = 0;
}

int	init(t_game *game)
{
	game->costa = 0;
	game->costb = 0;
	game->lista = malloc(sizeof(t_stack));
	game->listb = malloc(sizeof(t_stack));
	game->indmin = malloc(sizeof(t_imin));
	game->error = 0;
	if (!game->lista || !game->listb)
	{
		cleanup_game(game);
		return (0);
	}
	init_stacks(game);
	if (game->ac == 2)
		return (handle_split_input(game) && check_input(game->lista));
	else if (game->ac > 2)
	{
		game->error = check_alpha((game->av + 1));
		game->maxsize = game->ac - 1;
		if (!init_lists(game))
			return (0);
		fill_lists_from_args(game);
		return (check_input(game->lista));
	}
	cleanup_game(game);
	return (0);
}
