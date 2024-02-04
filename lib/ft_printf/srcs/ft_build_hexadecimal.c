/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:25 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:25 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_hexadecimal(t_node **list, int nb, const char *base)
{
	long	nbr;

	nbr = (long) nb;
	if (nbr < 0)
		nbr = 4294967295 + nbr + 1;
	if (nbr < 16)
		lstadd_back(list, lstnew(*(base + nbr)));
	if (nbr >= 16)
	{
		ft_build_hexadecimal(list, nbr / 16, base);
		ft_build_hexadecimal(list, nbr % 16, base);
	}
}
