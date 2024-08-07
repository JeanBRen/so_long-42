/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:12:45 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:21:37 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
// %4 == 0 up 1 down 2 left 3 right 
void	moove_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy.count)
	{
		if (rand() % 4 == 0 && game->map.map[(game->enemy.pos_y[i] / BITS_SIZE)
				- 1][(game->enemy.pos_x[i] / BITS_SIZE)] != '1')
			game->enemy.pos_y[i] -= 64;
		else if (rand() % 4 == 1 && game->map.map[(game->enemy.pos_y[i]
					/ BITS_SIZE) + 1][(game->enemy.pos_x[i]
				/ BITS_SIZE)] != '1')
			game->enemy.pos_y[i] += 64;
		else if (rand () % 4 == 2 && game->map.map[(game->enemy.pos_y[i]
					/ BITS_SIZE)][(game->enemy.pos_x[i]
				/ BITS_SIZE) - 1] != '1')
			game->enemy.pos_x[i] -= 64;
		else if (rand () % 4 == 3 && game->map.map[(game->enemy.pos_y[i]
					/ BITS_SIZE)][(game->enemy.pos_x[i]
				/ BITS_SIZE) + 1] != '1')
			game->enemy.pos_x[i] += 64;
		i++;
	}
}

void	render_arround(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy.count)
	{
		render_square(game, game->map.map[(game->enemy.pos_y[i] / BITS_SIZE)
			- 1][(game->enemy.pos_x[i] / BITS_SIZE)], game->enemy.pos_x[i]
			/ BITS_SIZE, game->enemy.pos_y[i] / BITS_SIZE);
		render_square(game, game->map.map[(game->enemy.pos_y[i] / BITS_SIZE)
			+ 1][(game->enemy.pos_x[i] / BITS_SIZE)], game->enemy.pos_x[i]
			/ BITS_SIZE, game->enemy.pos_y[i] / BITS_SIZE + 2);
		render_square(game, game->map.map[(game->enemy.pos_y[i] / BITS_SIZE)]
		[(game->enemy.pos_x[i] / BITS_SIZE + 1)], game->enemy.pos_x[i]
			/ BITS_SIZE + 1, game->enemy.pos_y[i] / BITS_SIZE + 1);
		render_square(game, game->map.map[(game->enemy.pos_y[i] / BITS_SIZE)]
		[(game->enemy.pos_x[i] / BITS_SIZE - 1)], game->enemy.pos_x[i]
			/ BITS_SIZE - 1, game->enemy.pos_y[i] / BITS_SIZE + 1);
		i++;
	}
}

void	put_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy.count)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->enemy.e_right.img, game->enemy.pos_x[i] - pos_map_x(game)
			* BITS_SIZE, game->enemy.pos_y[i] + 64 - pos_map_y(game)
			* BITS_SIZE);
		i++;
	}
	touch_ennemy(game);
	render_arround(game);
}
