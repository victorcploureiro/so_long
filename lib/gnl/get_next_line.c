/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:37:56 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/20 11:37:58 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*build_string(t_buffered **list)
{
	int			i;
	int			size;
	char		*str;
	t_buffered	*tmp;

	size = 0;
	tmp = *list;
	while (tmp && ++size && tmp -> character != '\n')
		tmp = tmp -> next;
	str = (char *) malloc(size + 1);
	if (!str)
		return (free_memory(list));
	i = 0;
	while (*list && i < size)
	{
		tmp = *list;
		*(str + i++) = (*list)-> character;
		*list = (*list)-> next;
		free(tmp);
	}
	*(str + i) = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	ssize_t				i;
	ssize_t				status;
	static char			buffer[BUFFER_SIZE];
	static t_buffered	*list;

	i = 0;
	if (list && lstfind_character(list, '\n'))
		return (build_string(&list));
	status = read(fd, buffer, BUFFER_SIZE);
	if (status == -1 || fd == -1)
		return (free_memory(&list));
	i = 0;
	if (status)
		while (i < status)
			lstadd_back(&list, lstnew(*(buffer + i++)));
	if (status)
		return (get_next_line(fd));
	else if (list)
		return (build_string(&list));
	return (NULL);
}
