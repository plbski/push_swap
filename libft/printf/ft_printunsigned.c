/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:05:32 by cbopp             #+#    #+#             */
/*   Updated: 2024/10/07 14:24:33 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unsignedlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unsignedlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = 48 + (n % 10);
		n /= 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int n)
{
	int		char_printed;
	char	*str;

	char_printed = 0;
	if (n == 0)
		char_printed += write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		char_printed += ft_putstr(str);
		free(str);
	}
	return (char_printed);
}
