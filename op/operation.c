#include "../pushswap.h"

int	*rotstring(t_stack *pile)
{
	unsigned int	j;
	int				stack;

	j = 0;
	stack = pile->list[j];
	while (j < pile->size - 1)
	{
		pile->list[j] = pile->list[j + 1];
		j ++;
	}
	pile->list[pile->size -1] = stack;
	return (pile->list);
}

int	*revrotstring(t_stack *pile)
{
	unsigned int	j;
	int				stack;

	j = pile->size - 1;
	stack = pile->list[j];
	while (j > 0)
	{
		pile->list[j] = pile->list[j - 1];
		j --;
	}
	pile->list[0] = stack;
	return (pile->list);
}

int	*swap(t_stack *pile)
{
	unsigned int	i;

	i = pile->list[0];
	pile->list[0] = pile->list[1];
	pile->list[1] = i;
	return (pile->list);
}
