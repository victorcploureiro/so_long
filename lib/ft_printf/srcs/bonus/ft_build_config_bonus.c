/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_config_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:09 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:40:09 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_build_config(t_format **conf, int nb)
{
	(*conf)-> c = ' ';
	if ((*conf)-> flags & LEFT)
		(*conf)-> flags &= ~ZERO;
	if ((*conf)-> precision >= 0)
		(*conf)-> flags &= ~ZERO;
	if ((*conf)-> flags & ZERO)
		(*conf)-> c = '0';
	(*conf)-> sign = 0;
	if (nb < 0)
		(*conf)-> sign = '-';
	else if ((*conf) && (*conf)-> flags & PLUS && nb > -1)
		(*conf)-> sign = '+';
	else if ((*conf)-> flags & SPACE)
		(*conf)-> sign = ' ';
	if ((*conf)-> sign)
		(*conf)-> width--;
}
