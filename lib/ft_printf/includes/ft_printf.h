/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:31 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:40:31 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"

typedef struct s_node
{
	int				character;
	struct s_node	*next;
}					t_node;

void	ft_build_hexadecimal(t_node **list, int nb, const char *base);
void	ft_build_number(t_node **list, int nb);
void	ft_build_pointer(t_node **list, unsigned long nb, const char *base);
void	ft_build_string(t_node **list, const char *str);
void	ft_build_unsigned(t_node **list, unsigned int nb);
t_node	*lstnew(int character);
t_node	*lstlast(t_node *list);
void	lstadd_back(t_node **list, t_node *node);
size_t	lstsize(t_node *list);
int		ft_printf(const char *fmt, ...);

#endif
