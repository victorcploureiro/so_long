/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:38:22 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:38:22 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_data
{
	char			initiated;
	int				fd;
	ssize_t			status;
	char			*buffer;
	struct s_string	*buffered;
}					t_data;

typedef struct s_string
{
	char			character;
	struct s_string	*next;
}					t_buffered;

char		*free_memory(t_buffered **list);
char		*get_next_line(int fd);
void		lstadd_back(t_buffered **list, t_buffered *new);
int			lstfind_character(t_buffered *list, char character);
t_buffered	*lstlast(t_buffered *list);
t_buffered	*lstnew(char character);

#endif
