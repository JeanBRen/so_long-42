/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:33:28 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/29 10:56:19 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || x > game->map.length || y < 0 || y > game->map.height)
		return ;
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	map[y][x] = 'F';
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
}

int	start_x(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	start_y(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_map(char *map_line, t_game *game)
{
	char	**map;

	map = ft_split(map_line, '\n');
	free(map_line);
	if (!map)
		error_management(1, game);
	check_wall(game, map);
	if (!start_x(map) || !start_y(map))
	{
		ft_free(map);
		ft_free(game->map.map);
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
	flood_fill(map, game, start_x(map), start_y(map));
	if (verif_map(map) == 1)
	{
		ft_free(map);
		ft_free(game->map.map);
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
	ft_free(map);
}
