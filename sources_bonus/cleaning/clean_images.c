/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:03:05 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:03:51 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_images(t_game *game)
{
	if (game->player.img)
		mlx_destroy_image(game->win.mlx_ptr, game->player.img);
	if (game->player_l.img)
		mlx_destroy_image(game->win.mlx_ptr, game->player_l.img);
	if (game->floor.img)
		mlx_destroy_image(game->win.mlx_ptr, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->win.mlx_ptr, game->wall.img);
	if (game->collectible.img)
		mlx_destroy_image(game->win.mlx_ptr, game->collectible.img);
	if (game->door.img)
		mlx_destroy_image(game->win.mlx_ptr, game->door.img);
}

void	destroy_idle(t_game *game)
{
	if (game->play.idle1.img)
		mlx_destroy_image(game->win.mlx_ptr, game->play.idle1.img);
	if (game->play.idle2.img)
		mlx_destroy_image(game->win.mlx_ptr, game->play.idle2.img);
	if (game->play.idle3.img)
		mlx_destroy_image(game->win.mlx_ptr, game->play.idle3.img);
	if (game->play.idle1_l.img)
		mlx_destroy_image(game->win.mlx_ptr, game->play.idle1_l.img);
	if (game->play.idle2_l.img)
		mlx_destroy_image(game->win.mlx_ptr, game->play.idle2_l.img);
	if (game->play.idle3_l.img)
		mlx_destroy_image(game->win.mlx_ptr, game->play.idle3_l.img);
}
