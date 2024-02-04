/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:50 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:50 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	build(t_node **list, t_node *characters, int len, t_format *conf)
{
	if (conf && len > conf -> precision && conf -> precision > -1)
		len = conf -> precision;
	if (conf && !(conf -> flags & LEFT))
		while (len < conf -> width--)
			lstadd_back(list, lstnew(' '));
	if (conf && characters && conf -> precision > -1)
		lstcat(list, &characters, conf -> precision);
	else if (characters)
		lstcat(list, &characters, lstsize(characters));
	while (conf && len < conf -> width--)
		lstadd_back(list, lstnew(' '));
}

void	ft_build_string(t_node **list, const char *str, t_format *conf)
{
	t_node	*characters;
	int		len;

	len = 0;
	characters = 0;
	if (!str)
	{
		if (conf && conf -> precision > -1 && conf -> precision < 6)
			conf -> precision = -2;
		ft_build_string(list, "(null)", conf);
		return ;
	}
	else if (!conf || conf -> precision > -2)
		while (*(str + len))
			lstadd_back(&characters, lstnew(*(str + len++)));
	build(list, characters, len, conf);
}
