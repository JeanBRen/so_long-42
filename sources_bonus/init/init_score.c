/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:09:17 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:08:48 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	verif_number(t_game *game)
{
	if (!game->score.board.img || !game->score.zero.img || !game->score.one.img
		|| !game->score.two.img || !game->score.three.img
		|| !game->score.four.img || !game->score.five.img
		|| !game->score.six.img || !game->score.seven.img
		|| !game->score.eight.img || !game->score.nine.img)
	{
		ft_putstr_fd("At least one image doest not exists\n", 1);
		win_destroy(game);
	}
}

void	init_score(t_game *game)
{
	game->score.board.img = mlx_xpm_file_to_image(game->win.mlx_ptr, BOARD,
			&game->score.board.s_x, &game->score.board.s_y);
	game->score.zero.img = mlx_xpm_file_to_image(game->win.mlx_ptr, ZERO,
			&game->score.zero.s_x, &game->score.zero.s_y);
	game->score.one.img = mlx_xpm_file_to_image(game->win.mlx_ptr, ONE,
			&game->score.one.s_x, &game->score.one.s_y);
	game->score.two.img = mlx_xpm_file_to_image(game->win.mlx_ptr, TWO,
			&game->score.two.s_x, &game->score.two.s_y);
	game->score.three.img = mlx_xpm_file_to_image(game->win.mlx_ptr, THREE,
			&game->score.three.s_x, &game->score.three.s_y);
	game->score.four.img = mlx_xpm_file_to_image(game->win.mlx_ptr, FOUR,
			&game->score.four.s_x, &game->score.four.s_y);
	game->score.five.img = mlx_xpm_file_to_image(game->win.mlx_ptr, FIVE,
			&game->score.five.s_x, &game->score.five.s_y);
	game->score.six.img = mlx_xpm_file_to_image(game->win.mlx_ptr, SIX,
			&game->score.six.s_x, &game->score.six.s_y);
	game->score.seven.img = mlx_xpm_file_to_image(game->win.mlx_ptr, SEVEN,
			&game->score.seven.s_x, &game->score.seven.s_y);
	game->score.eight.img = mlx_xpm_file_to_image(game->win.mlx_ptr, EIGHT,
			&game->score.eight.s_x, &game->score.eight.s_y);
	game->score.nine.img = mlx_xpm_file_to_image(game->win.mlx_ptr, NINE,
			&game->score.nine.s_x, &game->score.nine.s_y);
	verif_number(game);
}
