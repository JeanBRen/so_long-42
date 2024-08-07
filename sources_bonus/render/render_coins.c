/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_coins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:43:27 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/30 16:53:51 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_coins(t_game *game, int x, int y)
{
	if (game->coins.frame == 1)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->coins.coin1.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (game->coins.frame == 2)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->coins.coin2.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (game->coins.frame == 3)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->coins.coin3.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (game->coins.frame == 4)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->coins.coin4.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (game->coins.frame == 5)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->coins.coin5.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (game->coins.frame == 6)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->coins.coin6.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
}

void	render_coins(t_game *game)
{
	int	x;
	int	y;

	y = pos_map_y(game);
	while (game->map.map[y])
	{
		x = pos_map_x(game);
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				put_coins(game, x, y + 1);
			x++;
		}
		y++;
	}
	if (game->coins.frame != 6)
		game->coins.frame++;
	else
		game->coins.frame = 1;
}
