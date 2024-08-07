/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:14:46 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:26:57 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	idle_player_l(t_game *game)
{
	if (game->player.i == 0)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->play.idle1_l.img, game->player.pos_x - pos_map_x(game)
			* BITS_SIZE, game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
		game->player.i++;
	}
	else if (game->player.i == 1)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->play.idle2_l.img, game->player.pos_x - pos_map_x(game)
			* BITS_SIZE, game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
		game->player.i++;
	}
	else if (game->player.i == 2)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->play.idle3_l.img, game->player.pos_x - pos_map_x(game)
			* BITS_SIZE, game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
		game->player.i = 0;
	}
}

void	idle_player(t_game *game)
{
	if (game->player.i == 0)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->play.idle1.img, game->player.pos_x - pos_map_x(game)
			* BITS_SIZE, game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
		game->player.i++;
	}
	else if (game->player.i == 1)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->play.idle2.img, game->player.pos_x - pos_map_x(game)
			* BITS_SIZE, game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
		game->player.i++;
	}
	else if (game->player.i == 2)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->play.idle3.img, game->player.pos_x - pos_map_x(game)
			* BITS_SIZE, game->player.pos_y + 64 - pos_map_y(game) * BITS_SIZE);
		game->player.i = 0;
	}
}

int	loop_idle(t_game *game)
{
	if (game->frame % 5000 == 0)
	{
		render_coins(game);
		if (game->right_or_left == 0)
			idle_player(game);
		else
			idle_player_l(game);
	}
	if (game->frame == 20000)
	{
		moove_enemies(game);
		put_enemies(game);
		game->frame = 1;
		return (0);
	}
	if ((game->frame % 400001 != 0))
	{
		game->frame++;
		return (0);
	}
	return (0);
}
