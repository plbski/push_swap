/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:55:25 by cbopp             #+#    #+#             */
/*   Updated: 2024/12/05 11:40:47 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	long	prev;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		prev = result;
		result = result * 10 + (*str - '0');
		if (result < prev)
			return (handle_overflow(sign));
		str++;
	}
	return (result * sign);
}
