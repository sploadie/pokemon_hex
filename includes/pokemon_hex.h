/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_hex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 14:24:48 by tgauvrit         ###   ########.fr       */
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

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	char			*title;
	int				width;
	int				height;
	void			*clear_img;
	void			*img;
	int				*img_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;
}					t_win;

typedef struct		s_cam
{
	int				x;
	int				y;
}					t_cam;

typedef struct		s_poke_data
{
	char			*name;
	void			*sprite_f;
	void			*sprite_b;
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
	t_cam			*camera;
	t_poke_data		**poke_db;
	int				mouse_x;
	int				mouse_y;
	int				update;
}					t_env;

void				throw_error(char *str);
void				*check_malloc(void *ret);

t_win				*gen_mlx_window(void *mlx, char *title, int x, int y);
void				new_img(t_win *win);

void				gen_clear_img(t_win *win);
void				clear_img(t_win *win);

t_cam				*gen_default_camera(void);

int					hex_expose_hook(void *env);
int					hex_key_hook(int keycode, void *env);
int					hex_mouse_hook(int button, int x, int y, void *env);
int					hex_mouse_move_hook(int x, int y, void *env_ptr);
int					hex_loop_hook(void *env_ptr);
void				gen_view(t_env *env);

t_poke_data			**gen_pokemon_data(void	*mlx);

#endif
