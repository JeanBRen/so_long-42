/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:29:10 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/26 17:19:41 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	win_condition(t_game *game)
{
	if (game->collect_count == 0 && game->map.map[game->player.pos_y
			/ BITS_SIZE][game->player.pos_x / BITS_SIZE] == 'E')
	{
		ft_putstr_fd("YOU WIN\n", 1);
		win_destroy(game);
	}
}
