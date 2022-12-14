/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:00:12 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 21:12:18 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_flag(va_list *args, t_flag_info *flag_info)
{
	int		n;
	int		neg;
	char	*arg;
	char	*prefix;

	neg = 0;
	arg = ft_int_to_str(va_arg(*args, int));
	prefix = ft_get_prefix_int(arg, flag_info);
	if (arg[0] == '-')
	{
		neg = 1;
		arg++;
	}
	n = ft_print_int_flag_sub(arg, flag_info, prefix);
	free(arg - neg);
	return (n);
}

int	ft_print_int_flag_sub(char *arg, t_flag_info *flag_info, char *prefix)
{
	int	n;
	int	pad_a;
	int	pad_b;

	if (flag_info->dot && flag_info->int_a < ft_str_len(arg))
	{
		if (!ft_str_cmp(arg, "0"))
			arg[0] = '\0';
	}
	pad_a = ft_neg_to_zero(flag_info->int_a - ft_str_len(arg));
	pad_b = flag_info->int_b - pad_a - ft_str_len(arg) - ft_str_len(prefix);
	if (flag_info->minus)
		n = ft_print_flag_sub3(arg, prefix, pad_a, pad_b);
	else if (flag_info->zero && !flag_info->dot)
		n = ft_print_flag_sub4(arg, prefix, pad_a, pad_b);
	else
		n = ft_print_flag_sub5(arg, prefix, pad_a, pad_b);
	return (n);
}

int	ft_print_uint_flag(va_list *args, t_flag_info *flag_info)
{
	int		n;
	char	*arg;
	char	*prefix;

	arg = ft_uint_to_str(va_arg(*args, unsigned int));
	prefix = "\0";
	n = ft_print_int_flag_sub(arg, flag_info, prefix);
	free(arg);
	return (n);
}
