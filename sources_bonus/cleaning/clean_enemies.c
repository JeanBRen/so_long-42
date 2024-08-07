/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:20:38 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 16:03:40 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_enemies(t_game *game)
{
	if (game->enemy.dir)
		free(game->enemy.dir);
	if (game->enemy.pos_x)
		free(game->enemy.pos_x);
	if (game->enemy.pos_y)
		free(game->enemy.pos_y);
}

void	destroy_enemies(t_game *game)
{
	if (game->enemy.e_right.img)
		mlx_destroy_image(game->win.mlx_ptr, game->enemy.e_right.img);
}
