/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:16 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:16 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned long nbr, const char *base, t_node **list)
{
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	if (nbr < 16)
		lstadd_back(list, lstnew(*(base + nbr)));
	if (nbr >= 16)
	{
		ft_putnbr(nbr / 16, base, list);
		ft_putnbr(nbr % 16, base, list);
	}
}

void	ft_build_pointer(t_node **list, unsigned long nb, const char *base)
{
	if (!nb)
	{
		ft_build_string(list, "(nil)");
		return ;
	}
	ft_build_string(list, "0x");
	ft_putnbr(nb, base, list);
}
