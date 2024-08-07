/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:50:45 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/02 10:04:45 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(t_game *game)
{
	int	height;

	height = 0;
	while (game->map.map[height])
		height++;
	return (height);
}

int	map_length(t_game *game)
{
	int	length;

	length = 0;
	if (!game->map.map[0])
		return (0);
	while (game->map.map[0][length])
		length++;
	return (length);
}

void	collect_count(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				game->collect_count++;
			x++;
		}
		y++;
	}
}

char	*full_line(int fd, t_game *game)
{
	char	*line;
	char	*map_line;

	map_line = ft_calloc(1, sizeof(char));
	if (!map_line)
	{
		close (fd);
		error_management (1, game);
	}
	line = get_next_line(fd);
	while (line)
	{
		map_line = ft_strjoin(map_line, line);
		free (line);
		if (!map_line)
		{
			close (fd);
			error_management(1, game);
		}
		line = get_next_line(fd);
	}
	free(line);
	return (map_line);
}

void	read_map(char *av[], t_game *game)
{
	char	*map_line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_management(0, game);
	map_line = full_line(fd, game);
	close (fd);
	game->map.map = ft_split(map_line, '\n');
	if (!game->map.map)
	{
		free(map_line);
		error_management(1, game);
	}
	game->map.height = map_height(game);
	game->map.length = map_length(game);
	game->collect_count = 0;
	collect_count(game);
	if (game->collect_count < 1)
	{
		free(map_line);
		error_management(2, game);
	}
	check_map(map_line, game);
}
