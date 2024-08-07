/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenier <jrenier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:35:43 by jrenier           #+#    #+#             */
/*   Updated: 2024/08/01 16:13:13 by jrenier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/home/jrenier/minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../sources_bonus/GNL/get_next_line.h"

# define BITS_SIZE 64
# define PLAYER "./imgs/player/IDLE1.xpm"
# define PLAYER_L "./imgs/player/IDLE1_L.xpm"
# define WALL "./imgs/struct/wall.xpm"
# define FLOOR "./imgs/struct/floor.xpm"
# define COLLECTIBLE "./imgs/struct/collectible.xpm"
# define DOOR "./imgs/struct/door.xpm"
# define IDLE1 "./imgs/player/IDLE1.xpm"
# define IDLE2 "./imgs/player/IDLE2.xpm"
# define IDLE3 "./imgs/player/IDLE3.xpm"
# define IDLE1_L "./imgs/player/IDLE1_L.xpm"
# define IDLE2_L "./imgs/player/IDLE2_L.xpm"
# define IDLE3_L "./imgs/player/IDLE3_L.xpm"
# define ENEMY "./imgs/enemies/skeleton.xpm"

// SCORE BOARD
# define BOARD "./imgs/score/square.xpm"
# define ZERO "./imgs/score/0.xpm"
# define ONE "./imgs/score/1.xpm"
# define TWO "./imgs/score/2.xpm"
# define THREE "./imgs/score/3.xpm"
# define FOUR "./imgs/score/4.xpm"
# define FIVE "./imgs/score/5.xpm"
# define SIX "./imgs/score/6.xpm"
# define SEVEN "./imgs/score/7.xpm"
# define EIGHT "./imgs/score/8.xpm"
# define NINE "./imgs/score/9.xpm"

//COIN
# define COIN1 "./imgs/coins/coin1.xpm"
# define COIN2 "./imgs/coins/coin2.xpm"
# define COIN3 "./imgs/coins/coin3.xpm"
# define COIN4 "./imgs/coins/coin4.xpm"
# define COIN5 "./imgs/coins/coin5.xpm"
# define COIN6 "./imgs/coins/coin6.xpm"

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

typedef struct s_score
{
	t_img	board;
	t_img	zero;
	t_img	one;
	t_img	two;
	t_img	three;
	t_img	four;
	t_img	five;
	t_img	six;
	t_img	seven;
	t_img	eight;
	t_img	nine;
	int		width;
}	t_score;

typedef struct s_coins
{
	t_img	coin1;
	t_img	coin2;
	t_img	coin3;
	t_img	coin4;
	t_img	coin5;
	t_img	coin6;
	int		frame;
}	t_coins;

typedef struct s_enemy
{
	t_img	e_right;
	t_img	e_left;
	t_img	e_up;
	t_img	e_down;
	int		*dir;
	int		count;
	int		*pos_x;
	int		*pos_y;
}	t_enemy;

typedef struct s_play
{
	t_img	idle1;
	t_img	idle2;
	t_img	idle3;
	t_img	idle1_l;
	t_img	idle2_l;
	t_img	idle3_l;
}	t_play;

typedef struct s_game
{
	t_img	wall;
	t_img	collectible;
	t_img	floor;
	t_img	door;
	t_img	player;
	t_img	player_l;
	t_play	play;
	t_enemy	enemy;
	t_ptr	win;
	t_map	map;
	t_score	score;
	t_coins	coins;

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

// BONUS FONCTIONS
int		loop_idle(t_game *game);
void	init_idle(t_game *game);
void	destroy_enemies(t_game *game);
void	clean_enemies(t_game *game);
int		init_enemies(t_game *game);
void	put_enemies(t_game *game);
void	moove_enemies(t_game *game);
void	render_square(t_game *game, char square, int x, int y);
void	touch_ennemy(t_game *game);
void	init_score(t_game *game);
void	destroy_score(t_game *game);
void	render_score(t_game *game);
void	destroy_idle(t_game *game);
void	init_coin(t_game *game);
void	render_coins(t_game *game);
void	destroy_coins(t_game *game);
void	init_all(t_game *game);

#endif