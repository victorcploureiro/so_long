/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_character_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:13 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:40:13 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_build_character(t_node **list, int character, t_format *conf)
{
	conf -> flags &= ~PLUS;
	conf -> flags &= ~SPACE;
	conf -> flags &= ~HASH;
	conf -> flags &= ~ZERO;
	conf -> precision = -1;
	conf -> characters = 0;
	ft_build_config(&conf, 0);
	lstadd_front(&(conf -> characters), lstnew(character));
	ft_build(list, conf);
}
