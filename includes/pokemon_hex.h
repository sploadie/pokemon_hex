/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemon_hex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 13:21:19 by tgauvrit         ###   ########.fr       */
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

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	char			*title;
	int				width;
	int				height;
	void			*img;
	int				*img_data;
	int				img_bits_per_pixel;
	int				img_size_line;
	int				img_endian;
}					t_win;

typedef struct		s_cam
{
	double			x;
	double			y;
	double			z;
	int				mouse_x;
	int				mouse_y;
}					t_cam;

typedef struct		s_env
{
	t_win			*win;
	t_cam			*camera;
	int				update;
}					t_env;

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

void				throw_error(char *str);
void				*check_malloc(void *ret);

t_win				*gen_mlx_window(void *mlx, char *title, size_t x, size_t y);

void				new_img(t_fdf_win *win);
void				clear_img(t_fdf_win *win);

t_cam				*gen_default_camera(void);

int					hex_expose_hook(void *env);
int					hex_key_hook(int keycode, void *env);
int					hex_mouse_hook(int button, int x, int y, void *env);
int					hex_mouse_move_hook(int x, int y, void *env_ptr);
int					hex_loop_hook(void *env_ptr);

#endif
