/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:23:54 by vcarrara          #+#    #+#             */
/*   Updated: 2024/01/29 18:41:31 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	convert_png_to_texture(t_content *content)
{
	content->tile_png = mlx_load_png(TILE);
	content->wall_png = mlx_load_png(WALL);
	content->coin_png = mlx_load_png(COIN);
	content->player_png = mlx_load_png(PLAYER_U);
	content->portal_png = mlx_load_png(PORTAL);
	if (!content->tile_png
		|| !content->wall_png
		|| !content->coin_png
		|| !content->player_png
		|| !content->portal_png)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	convert_texture_to_image(mlx_t *mlx, t_content *content)
{
	content->tile_img = mlx_texture_to_image(mlx, content->tile_png);
	content->wall_img = mlx_texture_to_image(mlx, content->wall_png);
	content->coin_img = mlx_texture_to_image(mlx, content->coin_png);
	content->player_img = mlx_texture_to_image(mlx, content->player_png);
	content->portal_img = mlx_texture_to_image(mlx, content->portal_png);
}

void	resize_image(t_content *content)
{
	mlx_resize_image(content->tile_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->wall_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->coin_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->player_img, SIZE_IMG, SIZE_IMG);
	mlx_resize_image(content->portal_img, SIZE_IMG, SIZE_IMG);
}

void	validation_images(t_content *content)
{
	if (content->tile_img == NULL || content->wall_img == NULL \
		|| content->coin_img == NULL || content->player_img == NULL \
		|| content->portal_img == NULL)
		ft_printf("Image loading failed!\n");
}
