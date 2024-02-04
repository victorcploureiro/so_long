/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:13 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:36:38 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;
	unsigned char		*temp;
	size_t				i;

	d_ptr = (unsigned char *) dest;
	s_ptr = (const unsigned char *) src;
	temp = malloc(n);
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (i < n)
	{
		temp[i] = s_ptr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d_ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return (d_ptr);
}
