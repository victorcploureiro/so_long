/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:12 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:12 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_build_string(t_node **list, const char *str)
{
	if (!str)
	{
		ft_build_string(list, "(null)");
		return ;
	}
	while (*str)
		lstadd_back(list, lstnew(*str++));
}
