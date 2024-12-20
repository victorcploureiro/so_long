/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:04 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:04 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*lstnew(int character)
{
	t_node	*new;

	new = (t_node *) malloc(1 * sizeof(t_node));
	if (!new)
		return (0);
	new -> character = character;
	new -> next = 0;
	return (new);
}

t_node	*lstlast(t_node *list)
{
	if (!list)
		return (0);
	while (list -> next != 0)
		list = list -> next;
	return (list);
}

void	lstadd_back(t_node **list, t_node *node)
{
	if (!list || !node)
		return ;
	if (!(*list))
		*list = node;
	else
		lstlast(*list)-> next = node;
}

size_t	lstsize(t_node *list)
{
	size_t	size;

	if (!list)
		return (0);
	size = 0;
	while (list)
	{
		size++;
		list = list -> next;
	}
	return (size);
}
