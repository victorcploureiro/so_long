/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:20:05 by vcarrara          #+#    #+#             */
/*   Updated: 2024/02/05 17:51:49 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	next_step(t_data *data, int32_t x, int32_t y)
{
	data->map->matrix[data->posix->y_plyr][data->posix->x_plyr] = '0';
	render_move_player_v(data, x, y);
	render_move_player_h(data, x, y);
	ft_printf("Moves: %d\n", ++data->move);
	if (data->map->matrix[y][x] == 'C')
	{
		data->map->count_coin--;
		data->map->matrix[y][x] = '0';
		print_tile(data, (x * SIZE_IMG), (y * SIZE_IMG));
		print_player(data, (x * SIZE_IMG), (y * SIZE_IMG));
	}
	if (data->map->count_coin == 0)
	{
		data->map->matrix[data->posix->y_end][data->posix->x_end] = 'E';
		data->content->portal_img->enabled = true;
		if (data->map->matrix[y][x] == 'E')
		{
			ft_printf("Enough coins for today. Good job!.\n");
			free_end_game(data);
		}
	}
	data->map->matrix[y][x] = 'P';
}

void	left_move(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x - 1;
	y = move_y;
	data->content->side_player = 0;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_x--;
	}
}

void	up_move(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x;
	y = move_y - 1;
	data->content->side_player = 1;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_y--;
	}
}

void	right_move(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x + 1;
	y = move_y;
	data->content->side_player = 2;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_x++;
	}
}

void	down_move(t_data *data, int32_t move_x, int32_t move_y)
{
	int32_t	x;
	int32_t	y;

	x = move_x;
	y = move_y + 1;
	data->content->side_player = 3;
	if (data->map->matrix[y][x] != '1')
	{
		next_step(data, x, y);
		move_y++;
	}
}
