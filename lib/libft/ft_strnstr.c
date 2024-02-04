/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:33:20 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:38:03 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_count;
	size_t	l_count;
	size_t	l_len;

	l_len = ft_strlen(little);
	if (l_len == 0)
		return ((char *)big);
	b_count = 0;
	while (big[b_count] && (b_count < len))
	{
		if (big[b_count] == little[0])
		{
			l_count = 1;
			while (l_count < l_len && big[b_count + l_count] == little[l_count]
				&& (b_count + l_count) < len)
			{
				l_count++;
			}
			if (l_count == l_len)
				return ((char *)&big[b_count]);
		}
		b_count++;
	}
	return (NULL);
}
