/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:49:24 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:35:59 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		count;
	t_list	*last;

	count = 1;
	last = lst;
	if (!lst)
		return (0);
	while (last->next != NULL)
	{
		count++;
		last = last->next;
	}
	return (last);
}
