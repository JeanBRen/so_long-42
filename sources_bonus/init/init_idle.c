/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_idle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:59:59 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:10:26 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_idle(t_game *game)
{
	game->player.i = 0;
	game->frame = 1;
	game->play.idle1.img = mlx_xpm_file_to_image(game->win.mlx_ptr, IDLE1,
			&game->player.s_x, &game->player.s_y);
	game->play.idle2.img = mlx_xpm_file_to_image(game->win.mlx_ptr, IDLE2,
			&game->player.s_x, &game->player.s_y);
	game->play.idle3.img = mlx_xpm_file_to_image(game->win.mlx_ptr, IDLE3,
			&game->player.s_x, &game->player.s_y);
	game->play.idle1_l.img = mlx_xpm_file_to_image(game->win.mlx_ptr, IDLE1_L,
			&game->player.s_x, &game->player.s_y);
	game->play.idle2_l.img = mlx_xpm_file_to_image(game->win.mlx_ptr, IDLE2_L,
			&game->player.s_x, &game->player.s_y);
	game->play.idle3_l.img = mlx_xpm_file_to_image(game->win.mlx_ptr, IDLE3_L,
			&game->player.s_x, &game->player.s_y);
}
