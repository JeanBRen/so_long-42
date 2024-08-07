/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:51:11 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:02:00 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_not_found(t_game *game)
{
	ft_putstr_fd("At least one image does not exists\n", 1);
	win_destroy(game);
}

void	init_images(t_game *game)
{
	game->player.img = mlx_xpm_file_to_image(game->win.mlx_ptr, PLAYER,
			&game->player.s_x, &game->player.s_y);
	game->player_l.img = mlx_xpm_file_to_image(game->win.mlx_ptr, PLAYER_L,
			&game->player_l.s_x, &game->player_l.s_y);
	game->wall.img = mlx_xpm_file_to_image(game->win.mlx_ptr, WALL,
			&game->wall.s_x, &game->wall.s_y);
	game->floor.img = mlx_xpm_file_to_image(game->win.mlx_ptr, FLOOR,
			&game->floor.s_x, &game->floor.s_y);
	game->door.img = mlx_xpm_file_to_image(game->win.mlx_ptr, DOOR,
			&game->door.s_x, &game->door.s_y);
	game->collectible.img = mlx_xpm_file_to_image(game->win.mlx_ptr,
			COLLECTIBLE, &game->door.s_x, &game->door.s_y);
	if (!game->collectible.img || !game->player.img || !game->player_l.img
		|| !game->wall.img || !game->floor.img || !game->door.img)
		image_not_found(game);
}
