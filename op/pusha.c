#include "../pushswap.h"

void	shift_up_a(t_game *game)
{
	unsigned int	i;

	i = game->lista->size;
	while (i > 0)
	{
		game->lista->list[i] = game->lista->list[i - 1];
		i--;
	}
}

void	shift_down_a(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->lista->size - 1)
	{
		game->lista->list[i] = game->lista->list[i + 1];
		i++;
	}
	game->lista->list[i] = 0;
}

void	pusha(t_game *game)
{
	int	temp;

	if (game->listb->size == 0)
		return ;
	temp = game->listb->list[0];
	shift_down_b(game);
	shift_up_a(game);
	game->lista->list[0] = temp;
	game->lista->size++;
	game->listb->size--;
}
