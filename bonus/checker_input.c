/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:05:00 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/05 13:15:58 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker_input(t_stack *lista)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < lista->size)
	{
		j = i + 1;
		while (j < lista->size)
		{
			if (lista->list[i] == lista->list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checker_alpha(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		if (temp[i][j] == '-' || temp[i][j] == '+')
			j++;
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
