/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:02:21 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:36:21 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	size_t			i;

	s_ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == (unsigned char) c)
		{
			return (&s_ptr[i]);
		}
		i++;
	}
	return (NULL);
}
