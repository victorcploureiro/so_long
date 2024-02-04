/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:28:45 by vcarrara          #+#    #+#             */
/*   Updated: 2024/02/04 12:39:57 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_data	*ft_pointer_game(void)
{
	static t_data	game;
	return (&game);
}

static void	args_check(const char *argv, char *str)
{
	int	len_arg;
	int	len_str;

	len_arg = (int)ft_strlen(argv);
	len_str = (int)ft_strlen(str);
	while (len_str >= 0)
	{
		if (argv[len_arg] != str[len_str])
		{
			ft_printf("OOPS... Invalid extension. %s", argv);
			exit (EXIT_FAILURE);
		}
		len_arg--;
		len_str--;
	}
}

int32_t	main(int argc, char *argv[])
{
	t_data	*game;

	if (argc != 2)
	{
		ft_printf("Missing arguments...");
		exit (EXIT_FAILURE);
	}
	args_check(argv[1], ".ber");
	game = ft_pointer_game();
	init_vars(game);
	build_matrix(game, argv[1]);
	init_game(game);
	free_end_game(game);
	return (EXIT_SUCCESS);
}
