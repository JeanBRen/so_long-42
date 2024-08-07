/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:22:31 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/24 17:55:09 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_map_x(t_game *game)
{
	if (game->win.check_x == 1)
		return (0);
	if (game->win.x - game->player.pos_x < 5 * BITS_SIZE)
		return ((game->player.pos_x / BITS_SIZE)
			- (game->win.x / BITS_SIZE) + 4);
	return (0);
}

int	pos_map_y(t_game *game)
{
	if (game->win.check_y == 1)
		return (0);
	if (game->win.y - game->player.pos_y < 3 * BITS_SIZE)
		return ((game->player.pos_y / BITS_SIZE)
			- (game->win.y / BITS_SIZE) + 4);
	return (0);
}

void	render_square(t_game *game, char square, int x, int y)
{
	if (square == '1')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->wall.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (square == '0')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->floor.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (square == 'C')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->collectible.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (square == 'E' && game->collect_count > 0)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->floor.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (square == 'E' && game->collect_count == 0)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->door.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
	if (square == 'P')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->floor.img, (x - pos_map_x(game)) * BITS_SIZE,
			(y - pos_map_y(game)) * BITS_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = pos_map_y(game);
	while (game->map.map[y])
	{
		x = pos_map_x(game);
		while (game->map.map[y][x])
		{
			render_square(game, game->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
}
