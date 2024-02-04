/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_characters_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:39:42 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:42 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

static void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *) s;
	while (n--)
	{
		if (*src == (unsigned char) c)
			return ((void *) src);
		src++;
	}
	return (0);
}

char	*ft_find_characters(const char *s, int c)
{
	size_t	size;
	char	*src;

	size = ft_strlen(s);
	src = ft_memchr(s, c, size + 1);
	return (src);
}
