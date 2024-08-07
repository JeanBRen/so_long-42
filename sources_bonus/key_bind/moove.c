/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:36 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/02 10:03:00 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// 97 == left, 119 == up , 100 = right , 115 = down
int	check_move(int key, t_game *game)
{
	if ((key == 97 || key == 65361) && game->map.map[(game->player.pos_y
				/ BITS_SIZE)][(game->player.pos_x / BITS_SIZE) - 1] == '1')
		return (1);
	if ((key == 119 || key == 65362) && game->map.map[(game->player.pos_y
				/ BITS_SIZE) - 1][(game->player.pos_x / BITS_SIZE)] == '1')
		return (1);
	if ((key == 100 || key == 65363) && game->map.map[(game->player.pos_y
				/ BITS_SIZE)][(game->player.pos_x / BITS_SIZE) + 1] == '1')
		return (1);
	if ((key == 115 || key == 65364) && game->map.map[(game->player.pos_y
				/ BITS_SIZE) + 1][(game->player.pos_x / BITS_SIZE)] == '1')
		return (1);
	return (0);
}

void	collectible(t_game *game)
{
	if (game->map.map[game->player.pos_y / BITS_SIZE]
		[game->player.pos_x / BITS_SIZE] == 'C')
	{
		game->map.map[game->player.pos_y / BITS_SIZE]
		[game->player.pos_x / BITS_SIZE] = '0';
		game->collect_count--;
	}
}

void	put_image_player(t_game *game)
{
	if (game->right_or_left == 1)
		mlx_put_image_to_window(game->win.mlx_ptr,
			game->win.win_ptr, game->player_l.img, game->player.pos_x
			- pos_map_x(game) * BITS_SIZE, game->player.pos_y + 64
			- pos_map_y(game) * BITS_SIZE);
	else
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->player.img, game->player.pos_x - pos_map_x(game) * BITS_SIZE,
			game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
}

int	moove(int key, t_game *game)
{	
	if ((key == 97 || key == 65361))
		game->right_or_left = 1;
	if ((key == 100 || key == 65363))
		game->right_or_left = 0;
	if ((key == 97 || key == 65361) && check_move(key, game) != 1)
		game->player.pos_x -= BITS_SIZE;
	if ((key == 119 || key == 65362) && check_move(key, game) != 1)
			game->player.pos_y -= BITS_SIZE;
	if ((key == 100 || key == 65363) && check_move(key, game) != 1)
		game->player.pos_x += BITS_SIZE;
	if ((key == 115 || key == 65364) && check_move(key, game) != 1)
		game->player.pos_y += BITS_SIZE;
	collectible(game);
	render_map(game);
	put_image_player(game);
	win_condition(game);
	put_enemies(game);
	return (0);
}

int	print_moove(int key, t_game *game)
{
	if ((key == 97 || key == 65361) && check_move(key, game) != 1)
	{
		game->count++;
		render_score(game);
	}		
	if ((key == 119 || key == 65362) && check_move(key, game) != 1)
	{
		game->count++;
		render_score(game);
	}
	if ((key == 100 || key == 65363) && check_move(key, game) != 1)
	{
		game->count++;
		render_score(game);
	}
	if ((key == 115 || key == 65364) && check_move(key, game) != 1)
	{
		game->count++;
		render_score(game);
	}
	return (0);
}
