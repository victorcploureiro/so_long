/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:31:37 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:37:36 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	srclen;

	len = 0;
	srclen = 0;
	while (src[srclen])
	{
		srclen++;
	}
	while (*dst && (size > 0))
	{
		dst++;
		len++;
		size--;
	}
	while (*src && (size > 1))
	{
		*dst++ = *src++;
		size--;
	}
	if (size == 1 || *src == 0)
	{
		*dst = '\0';
	}
	return (srclen + len);
}
