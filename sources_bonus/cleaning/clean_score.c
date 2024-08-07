/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:32:56 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/30 15:40:42 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_score(t_game *game)
{
	if (game->score.board.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.board.img);
	if (game->score.zero.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.zero.img);
	if (game->score.one.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.one.img);
	if (game->score.two.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.two.img);
	if (game->score.three.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.three.img);
	if (game->score.four.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.four.img);
	if (game->score.five.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.five.img);
	if (game->score.six.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.six.img);
	if (game->score.seven.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.seven.img);
	if (game->score.eight.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.eight.img);
	if (game->score.nine.img)
		mlx_destroy_image(game->win.mlx_ptr, game->score.nine.img);
}
