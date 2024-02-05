/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:42:19 by vcarrara          #+#    #+#             */
/*   Updated: 2024/02/05 17:17:44 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_move_player_v(t_data *data, int32_t col, int32_t row)
{
	if (data->content->side_player == 1)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_U);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
	else if (data->content->side_player == 3)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_D);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
}

void	render_move_player_h(t_data *data, int32_t col, int32_t row)
{
	if (data->content->side_player == 0)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_L);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
	else if (data->content->side_player == 2)
	{
		mlx_delete_image(data->mlx, data->content->player_img);
		mlx_delete_texture(data->content->player_png);
		data->content->player_png = mlx_load_png(PLAYER_R);
		data->content->player_img = mlx_texture_to_image(data->mlx, \
			data->content->player_png);
		mlx_resize_image(data->content->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->content->player_img, \
			(SIZE_IMG * col), (SIZE_IMG * row));
	}
}
