/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:56:49 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 15:35:03 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	calculate_width(t_game *game)
{
	game->score.width = 0;
	if (game->win.x > game->map.length * BITS_SIZE)
		game->score.width = game->map.length;
	else
		game->score.width = game->win.x / BITS_SIZE;
}

void	put_score_utils(t_game *game, int j, int i, char *count)
{
	if (count[j] == '3')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.three.img, i * BITS_SIZE, 0);
	if (count[j] == '4')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.four.img, i * BITS_SIZE, 0);
	if (count[j] == '5')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.five.img, i * BITS_SIZE, 0);
	if (count[j] == '6')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.six.img, i * BITS_SIZE, 0);
	if (count[j] == '7')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.seven.img, i * BITS_SIZE, 0);
	if (count[j] == '8')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.eight.img, i * BITS_SIZE, 0);
	if (count[j] == '9')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.nine.img, i * BITS_SIZE, 0);
}

void	put_score(t_game *game, int j, int i)
{
	char	*count;

	count = ft_itoa(game->count);
	if (!count)
		win_destroy(game);
	if ((size_t) j > ft_strlen(count))
	{
		free(count);
		return ;
	}
	if (count[j] == '0')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.zero.img, i * BITS_SIZE, 0);
	if (count[j] == '1')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.one.img, i * BITS_SIZE, 0);
	if (count[j] == '2')
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.two.img, i * BITS_SIZE, 0);
	put_score_utils(game, j, i, count);
	free(count);
}

void	render_score(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	calculate_width(game);
	while (i < game->score.width)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->score.board.img, i * BITS_SIZE, 0);
		i++;
	}
	i = game->score.width / 2;
	if (i < 0)
		i = 0;
	while (j < 5 && i < game->score.width)
	{
		put_score(game, j, i);
		j++;
		i++;
	}
}
