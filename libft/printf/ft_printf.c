/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:30:28 by cbopp             #+#    #+#             */
/*   Updated: 2024/11/10 19:28:26 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conversion(va_list v1, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(v1, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(v1, char *));
	else if (format == 'p')
		char_printed += ft_putptr(va_arg(v1, unsigned long long));
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(v1, int));
	else if (format == 'u')
		char_printed += ft_putunsigned(va_arg(v1, unsigned int));
	else if (format == 'x' || format == 'X')
		char_printed += ft_puthex(va_arg(v1, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	v1;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(v1, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_conversion(v1, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(v1);
	return (char_printed);
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = 't';
// 	char str[] = "hello";
// 	int num = 0xAA;
// 	int	dec = 1239481;
// 	unsigned int unum = 987654321;

// 	ft_printf("test: No Args\n");
// 	printf("testf: No Args\n");
// 	ft_printf("test char: %c\n", c);
// 	printf("testf char: %c\n", c);
// 	ft_printf("test str: %s\n", str);
// 	printf("testf str: %s\n", str);
// 	ft_printf("test ptr: %p %p \n", str, &str);
// 	printf("testf ptr: %p %p \n", str, &str);
// 	ft_printf("test dec: %d\n", dec);
// 	printf("testf dec: %d\n", dec);
// 	ft_printf("test int: %i\n", num);
// 	printf("testf int: %i\n", num);
// 	ft_printf("test uint: %u\n", unum);
// 	printf("testf uint: %u\n", unum);
// 	ft_printf("test hex: %x\n", unum);
// 	printf("testf hex: %x\n", unum);
// 	ft_printf("test HEX: %X\n", unum);
// 	printf("testf HEX: %X\n", unum);
// 	ft_printf("test %%\n");
// 	printf("testf %%\n");
// 	ft_printf(" NULL %s NULL", NULL);
// 	printf(" NULL %s NULL", NULL);
// 	printf("Standard printf: Null string: %s\n", NULL);
//     ft_printf("Custom  ft_printf: Null string: %s\n", NULL);
//  }