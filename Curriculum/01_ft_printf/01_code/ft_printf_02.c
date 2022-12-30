/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:00:34 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 22:54:40 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		i += ft_print_str("(nil)");
	if (ptr)
	{
		i += ft_print_str("0x");
		i = ft_print_uhex(ptr, i);
	}
	return (i);
}

int	ft_print_int(int n, int i)
{
	if (n == -2147483648)
		i += ft_print_str("-2147483648");
	else
	{
		if (n < 0)
		{
			i += ft_print_char('-');
			n *= -1;
		}
		if (9 < n)
		{
			i = ft_print_int(n / 10, i);
		}
		i += ft_print_char((n % 10) + '0');
	}
	return (i);
}

int	ft_print_uint(unsigned int n, int i)
{
	if (9 < n)
		i += ft_print_int(n / 10, i);
	i += ft_print_char((n % 10) + '0');
	return (i);
}

int	ft_print_hex(unsigned int n, int c, int i)
{
	int	r;

	if (15 < n)
		i += ft_print_hex(n / 16, c, i);
	r = n % 16;
	if (r < 10)
		i += ft_print_char(r + '0');
	if (9 < r)
		i += ft_print_char(r - 10 + 'a' - 'x' + c);
	return (i);
}

int	ft_print_uhex(unsigned long long n, int i)
{
	int	r;

	if (15 < n)
		i = ft_print_uhex(n / 16, i);
	r = n % 16;
	if (r < 10)
		i += ft_print_char(r + '0');
	if (9 < r)
		i += ft_print_char(r - 10 + 'a');
	return (i);
}

int	ft_print_hex_flag(unsigned int arg, char c, const char *str, int f)
{
	int	n;

	n = 0;
	if (arg && ft_char_in_str_n('#', str, f))
	{
		n += write(1, "0", 1);
		n += write(1, &c, 1);
	}
	n += ft_print_hex(arg, c, 0);
	return (n);
}

int	ft_print_int_flag(int arg, const char *str, int f)
{
	int	n;

	n = 0;
	if (ft_char_in_str_n('+', str, f) && 0 <= arg)
		n += write(1, "+", 1);
	else if (ft_char_in_str_n(' ', str, f) && 0 <= arg)
		n += write(1, " ", 1);
	n = ft_print_int(arg, n);
	return (n);
}
