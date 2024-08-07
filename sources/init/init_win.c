/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:20:50 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/24 18:16:14 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_game *game)
{
	game->win.check_y = 0 ;
	game->win.check_x = 0 ;
	if (game->win.x >= game->map.length * BITS_SIZE
		&& game->win.y >= game->map.height * BITS_SIZE)
		game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, game->map.length
				* BITS_SIZE, game->map.height * BITS_SIZE, "SO LONG");
	else
	{
		if (game->win.x > game->map.length * BITS_SIZE)
		{
			game->win.x = game->map.length * BITS_SIZE;
			game->win.check_x = 1;
		}
		if (game->win.y > game->map.height * BITS_SIZE)
		{
			game->win.y = game->map.height * BITS_SIZE;
			game->win.check_y = 1;
		}
		game->win.win_ptr = mlx_new_window(game->win.mlx_ptr,
				game->win.x, game->win.y, "SO LONG" );
	}
}
