/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:20 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:20 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_number(t_node **list, int nb)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		lstadd_back(list, lstnew('-'));
	}
	if (nbr < 10)
		lstadd_back(list, lstnew(nbr + 48));
	if (nbr >= 10)
	{
		ft_build_number(list, nbr / 10);
		ft_build_number(list, nbr % 10);
	}
}
