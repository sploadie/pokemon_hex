/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_hex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/09 15:27:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POKEMON_HEX_H
# define POKEMON_HEX_H

# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define DEF_TITLE "Pokemon Hex"
# define USAGE "Usage: pokemon_hex [Arena] [Size || X Size] [Y Size] [Title]\n"
# define DEF_X 800
# define DEF_Y 800

# define POKEMON_TOTAL 649
# define POKEMON_SPRITE_SIZE 96
# define MAP_WIDTH 100
# define MAP_HEIGHT 100
# define MAX_ENTITIES 1000

/* DEV MACROS */
# define CLOCKS_PER_HALF (CLOCKS_PER_SEC / 2)
# define MOVEMENT 3

/* SPRITE BANK MACROS */

# define SPRITE_BANK_SIZE 10
# define SPRITE_CURSOR 0
# define SPRITE_GRASS 1
# define SPRITE_SELECT 2
# define SPRITE_HP_BAR 3
# define SPRITE_HP_FILL 4

/* - */

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	char				*title;
	int					width;
	int					height;
	void				*img;
	int					*img_data;
	int					*sprite_data;
	int					img_bits_per_pixel;
	int					img_size_line;
	int					img_endian;
}						t_win;

typedef struct			s_cam
{
	int					x;
	int					y;
}						t_cam;

typedef struct			s_mlx_text
{
	char				*str;
	int					x;
	int					y;
	int					color;
	void				(*to_free)();
	struct s_mlx_text	*next;
}						t_mlx_text;

typedef struct			s_sprite
{
	void				*img;
	int					*img_data;
	int					width;
	int					height;
}						t_sprite;

typedef struct			s_stats
{
	int					hp;
	int					attack;
	int					defense;
	int					sp_attack;
	int					sp_defense;
	int					speed;
}						t_stats;

typedef struct			s_poke_data
{
	char				*name;
	t_sprite			**sprite;
	int					number;
	t_stats				stats;
	int					stat_total;
	int					attacks[4];
}						t_poke_data;

/*
** Tile ID is (it's index in env->map + 1) * -1
**
** Tile type corresponds  to it's sprite's index in the bank
**
** Tile x and y are it's grid x and y positions
**
** Tile sprite_x and sprite_y are it's pixel x and y positions
*/

typedef struct			s_tile
{
	int					type;
	int					id;
	int					x;
	int					y;
	int					sprite_x;
	int					sprite_y;
	struct s_entity		*entity;
}						t_tile;

/*
** Entity ID is the same as it's index in env->entities
**
** Entity Sprites correspond to sprites in pokemon_data:
** 0 - Left (Front)
** 1 - Right (Back)
** 2 - Up (Front Reverse)
** 3 - Down (Back Reverse)
*/

typedef struct			s_entity
{
	int					id;
	int					curr_sprite;
	int					rand_x;
	int					rand_y;
	t_poke_data			*poke_data;
	t_stats				stats;
	t_tile				*tile;
}						t_entity;

typedef struct			s_env
{
	t_win				*win;
	t_mlx_text			*mlx_text;
	t_cam				*cam;
	t_tile				*map;
	t_entity			*entities;
	t_poke_data			*poke_db;
	t_sprite			*sprite_bank;
	t_entity			*selected_entity;
	int					mouse_x;
	int					mouse_y;
	int					update;
}						t_env;

void					throw_error(char *str);
void					*check_malloc(void *ret);

t_win					*gen_mlx_window(void *mlx, char *title, int x, int y);

void					new_img(t_win *win);
void					gen_sprite_data(t_win *win);
void					clear_img(t_win *win);
void					put_sprite_to_image(t_env *env, t_sprite *sprite, int id, int x, int y);

t_cam					*gen_default_camera(void);

int						hex_expose_hook(void *env);
int						hex_key_hook(int keycode, void *env);
int						hex_mouse_hook(int button, int x, int y, void *env);
int						hex_mouse_move_hook(int x, int y, void *env_ptr);
int						hex_loop_hook(void *env_ptr);
void					gen_view(t_env *env);

t_tile					*gen_map(t_env *env);
int						tile_distance(t_tile *tile_a, t_tile *tile_b);
t_tile					*fetch_tile(t_env *env, int tile_id);
t_tile					*fetch_tile_at(t_env *env, int x, int y);

t_entity				*gen_entities(t_env *env);

t_poke_data				*gen_pokemon_data(void	*mlx);
t_sprite				*gen_sprite_bank(void *mlx);

#endif
