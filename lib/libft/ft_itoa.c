/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:22:53 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/01 12:35:24 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
	}
	else if (n == 0)
		return (i + 1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*ascii;
	size_t			digits;
	unsigned int	num;

	if (n < 0)
		num = (unsigned int) n * -1;
	else
		num = n;
	digits = count_digits(n);
	ascii = malloc(digits);
	if (ascii == NULL)
		return (NULL);
	*(ascii + digits - 1) = 0;
	while (digits > 1)
	{
		digits--;
		*(ascii + digits - 1) = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		*ascii = '-';
	return (ascii);
}
