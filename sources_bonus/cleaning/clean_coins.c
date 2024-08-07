/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_coins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:00:07 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/30 17:12:58 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_coins(t_game *game)
{
	if (game->coins.coin1.img)
		mlx_destroy_image(game->win.mlx_ptr, game->coins.coin1.img);
	if (game->coins.coin2.img)
		mlx_destroy_image(game->win.mlx_ptr, game->coins.coin2.img);
	if (game->coins.coin3.img)
		mlx_destroy_image(game->win.mlx_ptr, game->coins.coin3.img);
	if (game->coins.coin4.img)
		mlx_destroy_image(game->win.mlx_ptr, game->coins.coin4.img);
	if (game->coins.coin5.img)
		mlx_destroy_image(game->win.mlx_ptr, game->coins.coin5.img);
	if (game->coins.coin6.img)
		mlx_destroy_image(game->win.mlx_ptr, game->coins.coin6.img);
}
