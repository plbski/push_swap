#include "../pushswap.h"

void	shift_up_b(t_game *game)
{
	unsigned int	i;

	i = game->listb->size;
	while (i > 0)
	{
		game->listb->list[i] = game->listb->list[i - 1];
		i--;
	}
}

void	shift_down_b(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < game->listb->size - 1)
	{
		game->listb->list[i] = game->listb->list[i + 1];
		i++;
	}
	game->listb->list[i] = 0;
}

void	pushb(t_game *game)
{
	int	temp;

	if (game->lista->size == 0)
		return ;
	temp = game->lista->list[0];
	shift_down_a(game);
	shift_up_b(game);
	game->listb->list[0] = temp;
	game->lista->size--;
	game->listb->size++;
}
