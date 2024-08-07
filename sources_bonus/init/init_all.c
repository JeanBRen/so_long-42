/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:05:06 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/02 09:52:00 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_null_utils(t_game *game)
{
	game->score.board.img = NULL;
	game->score.zero.img = NULL;
	game->score.one.img = NULL;
	game->score.two.img = NULL;
	game->score.three.img = NULL;
	game->score.four.img = NULL;
	game->score.five.img = NULL;
	game->score.six.img = NULL;
	game->score.seven.img = NULL;
	game->score.eight.img = NULL;
	game->score.nine.img = NULL;
}

void	init_null(t_game *game)
{
	game->collectible.img = NULL;
	game->door.img = NULL;
	game->floor.img = NULL;
	game->player.img = NULL;
	game->player_l.img = NULL;
	game->wall.img = NULL;
	game->enemy.e_right.img = NULL;
	game->coins.coin1.img = NULL;
	game->coins.coin2.img = NULL;
	game->coins.coin3.img = NULL;
	game->coins.coin4.img = NULL;
	game->coins.coin5.img = NULL;
	game->coins.coin6.img = NULL;
	game->play.idle1.img = NULL;
	game->play.idle2.img = NULL;
	game->play.idle3.img = NULL;
	game->play.idle1_l.img = NULL;
	game->play.idle2_l.img = NULL;
	game->play.idle3_l.img = NULL;
	game->enemy.dir = NULL;
	game->enemy.pos_x = NULL;
	game->enemy.pos_y = NULL;
	init_null_utils(game);
}

void	init_all(t_game *game)
{
	init_null(game);
	init_win(game);
	init_images(game);
	init_enemies(game);
	init_coin(game);
	init_player(game);
	init_idle(game);
	init_score(game);
}
