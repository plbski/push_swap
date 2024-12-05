#include "pushswap.h"

static int	sorted(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->list[i] > stack->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game			game;

	if (ac < 2)
		return (1);
	game.ac = ac;
	game.av = av;
	if (!init(&game) || game.error == 1)
	{
		cleanup_game(&game);
		return (ft_printf("Error\n", 1));
	}
	if (!sorted(game.lista))
		turk_sort(&game);
	cleanup_game(&game);
	return (0);
}
