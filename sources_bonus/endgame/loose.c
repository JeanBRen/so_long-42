/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:29:25 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:04:41 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	touch_ennemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy.count)
	{
		if (game->player.pos_x == game->enemy.pos_x[i]
			&& game->player.pos_y == game->enemy.pos_y[i])
		{
			ft_putstr_fd("YOU LOOSE\n", 1);
			win_destroy(game);
		}
		i++;
	}
}
