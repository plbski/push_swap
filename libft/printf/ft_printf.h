/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:26:25 by cbopp             #+#    #+#             */
/*   Updated: 2024/11/10 19:27:58 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);

int	ft_putnbr(int n);

int	ft_putptr(unsigned long long ptr);

int	ft_puthex(unsigned int num, const char format);

int	ft_putunsigned(unsigned int n);

#endif