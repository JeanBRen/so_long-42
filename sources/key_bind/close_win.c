/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:42:46 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 13:42:00 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_destroy(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window (game->win.mlx_ptr, game->win.win_ptr);
	mlx_destroy_display (game->win.mlx_ptr);
	free (game->win.mlx_ptr);
	ft_free(game->map.map);
	exit (EXIT_SUCCESS);
	return (0);
}

int	escape_key(int key, t_game *game)
{
	if (key == 65307)
	{
		destroy_images(game);
		mlx_destroy_window (game->win.mlx_ptr, game->win.win_ptr);
		mlx_destroy_display (game->win.mlx_ptr);
		free (game->win.mlx_ptr);
		ft_free(game->map.map);
		exit (EXIT_SUCCESS);
	}	
	return (0);
}
