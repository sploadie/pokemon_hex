/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_hex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 19:58:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POKEMON_HEX_H
# define POKEMON_HEX_H

# include <mlx.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "libft.h"

# define DEF_TITLE "Pokemon Hex"
# define USAGE "Usage: pokemon_hex [Arena] [Size || X Size] [Y Size] [Title]\n"
# define DEF_X 800
# define DEF_Y 800

# define POKEMON_TOTAL 649
# define POKEMON_SPRITE_SIZE 96
# define MAP_WIDTH 100
# define MAP_HEIGHT 100
# define MAX_ENTITIES 100

/* SPRITE BANK MACROS */

# define SPRITE_BANK_SIZE 10
# define SPRITE_CURSOR 0
# define SPRITE_GRASS 1

/* - */

typedef struct		s_sprite
{
	void			*img;
	int				*img_data;
	int				x;
	int				y;
}					t_sprite;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	char			*title;
	int				width;
	int				height;
	void			*img;
	int				*img_data;
	int				*sprite_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;
}					t_win;

typedef struct		s_tile
{
	int				type;
	int				id;
	int				x;
	int				y;
	int				sprite_x;
	int				sprite_y;
	int				entity_id;
}					t_tile;

typedef struct		s_entity
{
	t_sprite		*curr_sprite;
	int				poke_id;
	int				map_index;
}					t_entity;

typedef struct		s_cam
{
	int				x;
	int				y;
}					t_cam;

typedef struct		s_poke_data
{
	char			*name;
	t_sprite		*sprite_f;
	t_sprite		*sprite_b;
	int				number;
	int				hp;
	int				attack;
	int				defense;
	int				sp_attack;
	int				sp_defense;
	int				speed;
	int				total;
}					t_poke_data;

typedef struct		s_env
{
	t_win			*win;
	t_cam			*cam;
	t_tile			**map;
	t_entity		**entities;
	t_poke_data		**poke_db;
	t_sprite		**sprite_bank;
	int				selected_entity;
	int				mouse_x;
	int				mouse_y;
	int				update;
}					t_env;

void				throw_error(char *str);
void				*check_malloc(void *ret);

t_win				*gen_mlx_window(void *mlx, char *title, int x, int y);

void				new_img(t_win *win);
void				gen_sprite_data(t_win *win);
void				clear_img(t_win *win);

t_cam				*gen_default_camera(void);

int					hex_expose_hook(void *env);
int					hex_key_hook(int keycode, void *env);
int					hex_mouse_hook(int button, int x, int y, void *env);
int					hex_mouse_move_hook(int x, int y, void *env_ptr);
int					hex_loop_hook(void *env_ptr);
void				gen_view(t_env *env);
t_tile				**gen_map(t_env *env);
t_entity			**gen_entities(t_env *env);

t_poke_data			**gen_pokemon_data(void	*mlx);
t_sprite			**gen_sprite_bank(void *mlx);

#endif
