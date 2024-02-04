/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:56 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:57 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr(unsigned long long nbr, const char *base, t_node **list)
{
	if (nbr < 16)
		lstadd_back(list, lstnew(*(base + nbr)));
	if (nbr >= 16)
	{
		ft_putnbr(nbr / 16, base, list);
		ft_putnbr(nbr % 16, base, list);
	}
}

void	ft_build_pointer(t_node **list, unsigned long long nb, t_format *conf)
{
	if (!nb)
	{
		if (conf -> precision < 6)
			conf -> precision = 5;
		ft_build_string(list, "(nil)", conf);
		return ;
	}
	conf -> flags &= ~HASH;
	if (conf -> flags & ZERO && conf -> precision == -1)
		conf -> precision = conf -> width - 2;
	conf -> flags &= ~ZERO;
	conf -> characters = 0;
	ft_putnbr(nb, HEX_LOWER, &(conf -> characters));
	if (conf -> precision > (int) lstsize(conf -> characters))
	{
		conf -> precision -= (int) lstsize(conf -> characters);
		while (conf -> precision--)
			lstadd_front(&(conf -> characters), lstnew('0'));
	}
	ft_build_config(&conf, 0);
	lstadd_front(&(conf -> characters), lstnew('x'));
	lstadd_front(&(conf -> characters), lstnew('0'));
	ft_build(list, conf);
}
