/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:04:09 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/05 13:15:24 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_input(t_stack *lista)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_alpha(char **temp)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (ft_isalpha(temp[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
