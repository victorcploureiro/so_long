/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:25:21 by vcarrara          #+#    #+#             */
/*   Updated: 2024/02/04 12:46:46 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/includes/ft_printf.h"

# define TILE_SIZE 64
# define SIZE_IMG 64
# define PLAYER_L "./textures/player_l.png"
# define PLAYER_R "./textures/player_r.png"
# define PLAYER_U "./textures/player_u.png"
# define PLAYER_D "./textures/player_d.png"
# define TILE "./textures/tile.png"
# define WALL "./textures/wall.png"
# define COIN "./textures/coin.png"
# define PORTAL "./textures/portal.png"

typedef struct s_positions_elements
{
	int32_t		x_end;
	int32_t		y_end;
	int32_t		x_plyr;
	int32_t		y_plyr;

}				t_posix;

typedef struct s_content
{
	mlx_texture_t		*wall_png;
	mlx_image_t			*wall_img;
	mlx_texture_t		*coin_png;
	mlx_image_t			*coin_img;
	mlx_texture_t		*player_png;
	mlx_image_t			*player_img;
	mlx_texture_t		*portal_png;
	mlx_image_t			*portal_img;
	mlx_texture_t		*tile_png;
	mlx_image_t			*tile_img;
	int					side_player;
}						t_content;

typedef struct s_map
{
	char		c;
	char		*buffer;
	char		**matrix;
	int32_t		read_bytes;
	int32_t		size_map;
	int32_t		count_rows;
	int32_t		count_cols;
	int32_t		count_person;
	int32_t		count_coin;
	int32_t		count_portal;
	int32_t		fd;
}				t_map;

typedef struct s_data
{
	mlx_t			*mlx;
	t_content		*content;
	t_map			*map;
	t_posix			*posix;
	int32_t			move;
}					t_data;

void	init_game(t_data *data);
void	init_vars(t_data *data);

void	read_file(const char *av, t_map *map);
void	build_matrix(t_data *data, const char *av);
void	ft_flood_fill(t_data *data);
void	render_map(t_data *data);
void	player_position(t_posix *posix, char **matrix);
void	count_elements(t_map *map, char **matrix);
void	check_format(t_map *map, char **matrix);
int		check_walls(t_map *map, char **matrix);
int		check_newlines(char *buffer);

int32_t	convert_png_to_texture(t_content *content);
void	convert_texture_to_image(mlx_t *mlx, t_content *content);
void	resize_image(t_content *content);
void	validation_images(t_content *content);
void	print_player(t_data *data, int32_t x, int32_t y);
void	print_tile(t_data *data, int32_t x, int32_t y);
void	print_wall(t_data *data, int32_t x, int32_t y);
void	print_coin(t_data *data, int32_t x, int32_t y);
void	print_portal(t_data *data, int32_t x, int32_t y);

void	up_move(t_data *data, int32_t move_x, int32_t move_y);
void	left_move(t_data *data, int32_t move_x, int32_t move_y);
void	down_move(t_data *data, int32_t move_x, int32_t move_y);
void	right_move(t_data *data, int32_t move_x, int32_t move_y);
void	move_player(mlx_key_data_t keyd, void *param);
void	render_move_player_v(t_data *data, int32_t col, int32_t row);
void	render_move_player_h(t_data *data, int32_t col, int32_t row);
void	render_hook_map(t_data *data);
void	put_elements_map(t_data *data, int32_t cols, int32_t rows);

void	delete_textures(t_content *content);
void	delete_images(mlx_t *mlx, t_content *content);
void	free_matrix(char **matrix);
int		free_end_game(t_data *data);
void	close_window(void *key);
void	free_allocations(char *buffer, char **matrix);

#endif
