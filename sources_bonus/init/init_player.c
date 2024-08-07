/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:49:36 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:56:58 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.pos_x = x * BITS_SIZE;
				game->player.pos_y = y * BITS_SIZE;
			}
			x++;
		}
		y++;
	}
}

int	init_player(t_game *game)
{
	game->player.addr = mlx_get_data_addr(game->player.img,
			&game->player.bits_per_pixel, &game->player.line_length,
			&game->player.endian);
	game->player.pos_x = 0;
	game->player.pos_y = 0;
	game->right_or_left = 0;
	player_pos(game);
	return (0);
}
