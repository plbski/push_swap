#include "pushswap.h"

int	countnum(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

void	cleanup_split(char **temp)
{
	int	i;

	if (!temp)
		return ;
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	cleanup_game(t_game *game)
{
	if (game->lista)
	{
		if (game->lista->list)
			free(game->lista->list);
		free(game->lista);
	}
	if (game->listb)
	{
		if (game->listb->list)
			free(game->listb->list);
		free(game->listb);
	}
	if (game->indmin)
		free(game->indmin);
}

int	init_lists(t_game *game)
{
	game->lista->list = malloc(sizeof(int) * game->maxsize);
	game->listb->list = malloc(sizeof(int) * game->maxsize);
	if (!game->lista->list || !game->listb->list)
	{
		cleanup_game(game);
		return (0);
	}
	return (1);
}

long	check(long num, t_game *game)
{
	if (num < -2147483648 || num > 2147483647)
		game->error = 1;
	return (num);
}
