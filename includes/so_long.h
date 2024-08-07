/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:35:43 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/02 10:06:10 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/jrenier/minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../sources/GNL/get_next_line.h"

# define BITS_SIZE 64
# define PLAYER "./imgs/player/IDLE1.xpm"
# define PLAYER_L "./imgs/player/IDLE1_L.xpm"
# define WALL "./imgs/struct/wall.xpm"
# define FLOOR "./imgs/struct/floor.xpm"
# define COLLECTIBLE "./imgs/coins/coin1.xpm"
# define DOOR "./imgs/struct/door.xpm"

typedef struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		check_x;
	int		check_y;
}	t_ptr;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		pos_x;
	int		pos_y;
	int		s_x;
	int		s_y;
	int		i;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
}	t_map;

typedef struct s_game
{
	t_img	wall;
	t_img	collectible;
	t_img	floor;
	t_img	door;
	t_img	player;
	t_img	player_l;
	t_ptr	win;
	t_map	map;
	int		collect_count;
	int		count;
	int		right_or_left;
	int		frame;
}	t_game;

int		moove(int key, t_game *game);
int		escape_key(int key, t_game *game);
int		win_destroy(t_game *game);
int		init_back(t_game *game);
int		init_player(t_game *game);
int		print_moove(int key, t_game *game);
void	read_map(char *av[], t_game *game);
void	render_map(t_game *game);
void	init_win(t_game *game);
int		pos_map_y(t_game *game);
int		pos_map_x(t_game *game);
void	check_map(char *map_line, t_game *game);
void	check_game(t_game *game);
void	error_management(int error, t_game *game);
void	ft_free(char **map);
void	init_images(t_game *game);
void	win_condition(t_game *game);
void	destroy_images(t_game *game);
void	check_name(char *av[]);
void	check_wall(t_game *game, char **map);
void	put_image_player(t_game *game);

#endif