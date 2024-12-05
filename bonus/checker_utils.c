#include "checker.h"

int	alloc_stacks(t_game *game)
{
	game->lista = (t_stack *)malloc(sizeof(t_stack));
	if (!game->lista)
		return (1);
	game->listb = (t_stack *)malloc(sizeof(t_stack));
	if (!game->listb)
	{
		free(game->lista);
		return (1);
	}
	game->lista->size = 0;
	game->listb->size = 0;
	return (0);
}

int	alloc_lists(t_game *game)
{
	game->lista->list = (int *)malloc(sizeof(int) * game->maxsize);
	if (!game->lista->list)
	{
		free(game->lista);
		free(game->listb);
		return (1);
	}
	game->listb->list = (int *)malloc(sizeof(int) * game->maxsize);
	if (!game->listb->list)
	{
		free(game->lista->list);
		free(game->lista);
		free(game->listb);
		return (1);
	}
	return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	free(s1);
	return (result);
}

int	is_sorted(t_stack *stack)
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
