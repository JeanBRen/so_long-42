/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:11:01 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/02 10:06:38 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *av[])
{
	int	len;

	len = ft_strlen(av[1]);
	if (av[1][len - 4] != '.')
	{
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
	if (av[1][len - 3] != 'b')
	{
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
	if (av[1][len - 2] != 'e')
	{
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
	if (av[1][len - 1] != 'r')
	{
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
}

int	hook(int key, t_game *game)
{
	print_moove(key, game);
	moove(key, game);
	escape_key(key, game);
	return (0);
}

void	is_file(char *av[])
{
	int	fd;

	fd = open(av[1], __O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
		close(fd);
	}
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac < 2)
		exit (EXIT_FAILURE);
	check_name(av);
	is_file(av);
	read_map(av, &game);
	check_game(&game);
	game.count = 0;
	game.win.mlx_ptr = NULL;
	game.win.mlx_ptr = mlx_init();
	if (!game.win.mlx_ptr)
	{
		ft_free(game.map.map);
		exit(EXIT_FAILURE);
	}
	mlx_get_screen_size(game.win.mlx_ptr, &game.win.x, &game.win.y);
	init_win(&game);
	init_images(&game);
	init_player(&game);
	render_map(&game);
	put_image_player(&game);
	mlx_hook(game.win.win_ptr, 2, 1L << 0, hook, &game);
	mlx_hook(game.win.win_ptr, 17, 1L << 2, win_destroy, &game);
	mlx_loop(game.win.mlx_ptr);
}
