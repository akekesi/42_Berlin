/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:04:21 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 22:30:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str_;

	str_ = (char *)str;
	while (*str_ != c)
	{
		if (!*str_)
			return (NULL);
		str_++;
	}
	return (str_);
}