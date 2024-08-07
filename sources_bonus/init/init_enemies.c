/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:09:34 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:07:05 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	malloc_enemies(t_game *game)
{
	game->enemy.dir = NULL;
	game->enemy.pos_x = NULL;
	game->enemy.pos_y = NULL;
	game->enemy.dir = malloc(game->enemy.count * sizeof(int));
	if (!game->enemy.dir)
		win_destroy(game);
	game->enemy.pos_x = malloc(game->enemy.count * sizeof(int));
	game->enemy.pos_y = malloc(game->enemy.count * sizeof(int));
}

void	enemies_count(t_game *game)
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
			if (game->map.map[y][x] == 'A')
				game->enemy.count++;
			x++;
		}
		y++;
	}
	malloc_enemies(game);
}

void	enemy_pos(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'A')
			{
				game->enemy.pos_x[i] = x * BITS_SIZE;
				game->enemy.pos_y[i] = y * BITS_SIZE;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	init_enemies(t_game *game)
{
	game->enemy.count = 0;
	enemies_count(game);
	enemy_pos(game);
	game->enemy.e_right.img = mlx_xpm_file_to_image(game->win.mlx_ptr,
			ENEMY, &game->enemy.e_right.s_x, &game->enemy.e_right.s_x);
	return (0);
}
