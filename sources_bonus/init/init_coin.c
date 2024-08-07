/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:53:13 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:10:07 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	verif_coins(t_game *game)
{
	if (!game->coins.coin1.img || !game->coins.coin2.img
		|| !game->coins.coin3.img || !game->coins.coin4.img
		|| !game->coins.coin5.img || !game->coins.coin6.img)
	{
		ft_putstr_fd("At least one image doest not exists\n", 1);
		win_destroy(game);
	}
}

void	init_coin(t_game *game)
{
	game->coins.frame = 1;
	game->coins.coin1.img = mlx_xpm_file_to_image(game->win.mlx_ptr, COIN1,
			&game->coins.coin1.s_x, &game->coins.coin1.s_y);
	game->coins.coin2.img = mlx_xpm_file_to_image(game->win.mlx_ptr, COIN2,
			&game->coins.coin2.s_x, &game->coins.coin2.s_y);
	game->coins.coin3.img = mlx_xpm_file_to_image(game->win.mlx_ptr, COIN3,
			&game->coins.coin3.s_x, &game->coins.coin3.s_y);
	game->coins.coin4.img = mlx_xpm_file_to_image(game->win.mlx_ptr, COIN4,
			&game->coins.coin4.s_x, &game->coins.coin4.s_y);
	game->coins.coin5.img = mlx_xpm_file_to_image(game->win.mlx_ptr, COIN5,
			&game->coins.coin5.s_x, &game->coins.coin5.s_y);
	game->coins.coin6.img = mlx_xpm_file_to_image(game->win.mlx_ptr, COIN6,
			&game->coins.coin6.s_x, &game->coins.coin6.s_y);
	verif_coins(game);
}
