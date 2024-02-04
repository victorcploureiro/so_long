/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:08:49 by vcarrara          #+#    #+#             */
/*   Updated: 2024/02/04 12:11:21 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_player(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->player_img, x, y);
}

void	print_portal(t_data *data, int32_t x, int32_t y)
{
	data->content->portal_img->enabled = false;
	mlx_image_to_window(data->mlx, data->content->portal_img, x, y);
}

void	print_coin(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->coin_img, x, y);
}

void	print_tile(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->tile_img, x, y);
}

void	print_wall(t_data *data, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, data->content->wall_img, x, y);
}
