/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:50:39 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/29 11:14:24 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_size(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
			x++;
		if (x != game->map.length)
		{
			error_management(3, game);
		}
		y++;
	}
}

void	check_wall(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if ((x == 0 || x == game->map.length - 1)
				&& game->map.map[y][x] != '1')
			{
				ft_free(map);
				error_management(3, game);
			}
			if ((y == 0 || y == game->map.height - 1)
				&& game->map.map[y][x] != '1')
			{
				ft_free(map);
				error_management(3, game);
			}
			x++;
		}
		y++;
	}
}

void	check_chara(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] != 'P' && game->map.map[y][x] != '0'
				&& game->map.map[y][x] != '1' && game->map.map[y][x] != 'C'
					&& game->map.map[y][x] != 'E' && game->map.map[y][x] != 'A')
			{
				ft_free(game->map.map);
				ft_putstr_fd("Invalid map\n", 1);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

void	check_player(t_game *game)
{
	int	x;
	int	y;
	int	e;
	int	p;

	y = -1;
	e = 0;
	p = 0;
	while (game->map.map[++y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
				p++;
			if (game->map.map[y][x] == 'E')
				e++;
			x++;
		}
	}
	if (p != 1 || e != 1)
	{
		error_management(3, game);
	}
}

void	check_game(t_game *game)
{
	check_size(game);
	check_player(game);
	check_chara(game);
}
