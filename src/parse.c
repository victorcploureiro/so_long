/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:43:40 by vcarrara          #+#    #+#             */
/*   Updated: 2024/02/04 12:08:01 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_elements(t_map *map, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (matrix[y][x] == 'P')
				map->count_person++;
			if (matrix[y][x] == 'C')
				map->count_coin++;
			if (matrix[y][x] == 'E')
				map->count_portal++;
			x++;
		}
		y++;
	}
}

int	check_walls(t_map *map, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] != '\0')
		{
			if (matrix[0][x] != '1'
				|| matrix[map->count_rows - 1][x] != '1'
				|| matrix[y][0] != '1'
				|| matrix[y][map->count_cols - 1] != '1')
			{
				ft_printf("ERROR. Contents of the wall invalid.\n");
				free_allocations(map->buffer, matrix);
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	check_newlines(char *buffer)
{
	int	index;

	index = 0;
	if (buffer[0] == '\n')
	{
		ft_printf("ERROR. Invalid map (exceeds newline limit).\n");
		free(buffer);
		exit (EXIT_FAILURE);
	}
	while (buffer[index] != '\0')
	{
		if ((buffer[index] == '\n' && buffer[index - 1] != '1')
			|| (buffer[index] == '\n' && buffer[index + 1] == '\n'))
		{
			ft_printf("ERROR. Invalid map (exceeds newline limit).\n");
			free(buffer);
			exit (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

void	player_position(t_posix *posix, char **matrix)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'P')
			{
				posix->y_plyr = y;
				posix->x_plyr = x;
			}
			if (matrix[y][x] == 'E')
			{
				posix->y_end = y;
				posix->x_end = x;
			}
			x++;
		}
		y++;
	}
}

void	check_format(t_map *map, char **matrix)
{
	int x;
	int y;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
			x++;
		if (x != map->count_cols)
		{
			ft_printf("ERROR. Map has invalid format.\n");
			free_allocations(map->buffer, matrix);
		}
		y++;
	}
}
