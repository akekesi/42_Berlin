/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:19:41 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/05 16:19:41 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_neg_to_zero(int n)
{
	if (n < 0)
		return (0);
	return (n);
}

int	ft_max(int n1, int n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}
