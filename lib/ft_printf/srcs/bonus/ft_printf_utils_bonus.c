/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:33 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:33 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	lstadd_front(t_node **list, t_node *node)
{
	if (!list || !node)
		return ;
	node -> next = *list;
	*list = node;
}

void	lstadd_back(t_node **list, t_node *node)
{
	t_node	*tmp;

	if (!list || !node)
		return ;
	if (!(*list))
		*list = node;
	else
	{
		tmp = *list;
		while (tmp -> next != 0)
			tmp = tmp -> next;
		tmp -> next = node;
	}
}

size_t	lstsize(t_node *list)
{
	size_t	size;

	if (!list || list == 0)
		return (0);
	size = 0;
	while (list)
	{
		size++;
		list = list -> next;
	}
	return (size);
}

void	lstcat(t_node **list, t_node **src, int size)
{
	t_node	*tmp;

	while (*src)
	{
		tmp = *src;
		if (size-- > 0)
			lstadd_back(list, lstnew((*src)-> character));
		*src = (*src)-> next;
		free(tmp);
	}
}
