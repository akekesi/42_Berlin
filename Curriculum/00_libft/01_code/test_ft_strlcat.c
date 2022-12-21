/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:01:56 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/18 20:48:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"
// #include <bsd/string.h> // it works in external terminal (but not in vs code)
// compile: clear && gcc main.c ft_strlcat.c test_ft_strlcat.c -lbsd && ./a.out

int				test_ft_strlcat(void);
static int		test_check(int result, int result_ft, char * dest, char *dest_ft, int n);
static void	test_print(int result, int result_ft, char * dest, char *dest_ft);

int	test_ft_strlcat(void)
{
	char		*dest;
	char		*dest_ft;
	dest = (char *)malloc(sizeof(*dest) * 15);
	dest_ft = (char *)malloc(sizeof(*dest_ft) * 15);
	memset(dest, 'x', 15);
	memset(dest_ft, 'x', 15);
	const char	src[] = "12345678";
	size_t		n;
	int			i;
	int			result;
	int			result_ft;

	i = 1;
	n = 16;
	result = strlcat(dest, src, n);
	result_ft = ft_strlcat(dest_ft, src, n);
	test_print(result, result_ft, dest, dest_ft);
	if (!test_check(result, result_ft, dest, dest_ft, i++))
		return (0);
	return (1);
}

static int	test_check(int result, int result_ft, char * dest, char *dest_ft, int n)
{
	if ((result != result_ft) || strcmp(dest, dest_ft))
	{
		printf("Error-%d:\n", n);
		test_print(result, result_ft, dest, dest_ft);
		return (0);
	}
	return (1);
}

static void	test_print(int result, int result_ft, char * dest, char *dest_ft)
{
	printf("result:    %d\n", result);
	printf("result_ft: %d\n", result_ft);
	printf("dest:      %s\n", dest);
	printf("dest_ft:   %s\n", dest_ft);
}