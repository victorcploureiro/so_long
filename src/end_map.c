/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endal_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:50:05 by vcarrara          #+#    #+#             */
/*   Updated: 2024/01/29 19:43:28 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	delete_textures(t_content *content)
{
	mlx_delete_texture(content->tile_png);
	mlx_delete_texture(content->wall_png);
	mlx_delete_texture(content->player_png);
	mlx_delete_texture(content->coin_png);
	mlx_delete_texture(content->portal_png);
}

void	delete_images(mlx_t *mlx, t_content *content)
{
	mlx_delete_image(mlx, content->tile_img);
	mlx_delete_image(mlx, content->wall_img);
	mlx_delete_image(mlx, content->player_img);
	mlx_delete_image(mlx, content->coin_img);
	mlx_delete_image(mlx, content->portal_img);
}

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	free_end_game(t_data *data)
{
	delete_textures(data->content);
	delete_images(data->mlx, data->content);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free_matrix(data->map->matrix);
	exit (EXIT_SUCCESS);
}