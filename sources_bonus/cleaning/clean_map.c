/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:39:58 by jrenier           #+#    #+#             */
/*   Updated: 2024/07/29 11:04:14 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_management(int error, t_game *game)
{
	if (error == 0)
	{
		ft_putstr_fd("map does not exist\n", 1);
		exit (EXIT_FAILURE);
	}
	if (error == 1)
	{
		ft_putstr_fd("error with the malloc\n", 1);
		exit (EXIT_FAILURE);
	}
	if (error == 2)
	{
		ft_free(game->map.map);
		ft_putstr_fd("Invalid map : missing at least one collectible\n", 1);
		exit (EXIT_FAILURE);
	}
	if (error == 3)
	{
		ft_free(game->map.map);
		ft_putstr_fd("Invalid map\n", 1);
		exit (EXIT_FAILURE);
	}
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
