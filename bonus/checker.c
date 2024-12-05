#include "checker.h"

#include "checker.h"

static int	execute_operation(t_game *game, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		swap(game->lista);
	else if (!ft_strncmp(operation, "sb\n", 3))
		swap(game->listb);
	else if (!ft_strncmp(operation, "ss\n", 3))
		return (swap(game->lista) && swap(game->listb));
	else if (!ft_strncmp(operation, "pa\n", 3))
		pusha(game);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pushb(game);
	else if (!ft_strncmp(operation, "ra\n", 3))
		rotstring(game->lista);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rotstring(game->listb);
	else if (!ft_strncmp(operation, "rr\n", 3))
		return (rotstring(game->lista) && rotstring(game->listb));
	else if (!ft_strncmp(operation, "rra\n", 4))
		revrotstring(game->lista);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		revrotstring(game->listb);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		return (revrotstring(game->lista) && revrotstring(game->listb));
	else
		return (0);
	return (1);
}

static int	check_result(t_game *game)
{
	if (game->listb->size != 0)
		return (0);
	return (is_sorted(game->lista));
}

static char	*read_operation(void)
{
	char	buffer[5];
	int		bytes;
	char	*str;

	bytes = read(0, buffer, 1);
	if (bytes <= 0)
		return (NULL);
	buffer[1] = '\0';
	str = ft_strdup(buffer);
	while (bytes > 0 && buffer[0] != '\n')
	{
		bytes = read(0, buffer, 1);
		if (bytes > 0)
		{
			buffer[1] = '\0';
			str = ft_strjoin_free(str, buffer);
		}
	}
	return (str);
}

static int	process_operations(t_game *game)
{
	char	*operation;

	while (1)
	{
		operation = read_operation();
		if (!operation)
			break ;
		if (!execute_operation(game, operation))
		{
			free(operation);
			return (0);
		}
		free(operation);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		return (0);
	game.ac = argc;
	game.av = argv;
	if (checker_init(&game) != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!process_operations(&game))
	{
		ft_printf("Error\n");
		cleanup_game(&game);
		return (1);
	}
	if (check_result(&game))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup_game(&game);
	return (0);
}
