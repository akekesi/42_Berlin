/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:54:53 by akekesi           #+#    #+#             */
/*   Updated: 2022/08/12 18:54:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **beginn_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem -> next = *beginn_list;
	*beginn_list = elem;
}
