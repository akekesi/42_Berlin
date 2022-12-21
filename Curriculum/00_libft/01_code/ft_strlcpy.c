/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:54:12 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/18 15:43:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t n);
static int	hf_strlen(char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	int	i;
	int	len_src;

	len_src = hf_strlen((char *)src);
	i = 0;
	while ((i < ((int)n - 1)) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n)
		dest[i] = '\0';
	return (len_src);
}

static int	hf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}