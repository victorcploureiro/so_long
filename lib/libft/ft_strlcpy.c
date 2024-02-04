/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:22:08 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:37:41 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = 0;
	while (src[srclen] != '\0' && srclen + 1 < size)
	{
		dst[srclen] = src[srclen];
		srclen++;
	}
	if (size > 0)
		dst[srclen] = '\0';
	while (src[srclen] != '\0')
		srclen++;
	return (srclen);
}
