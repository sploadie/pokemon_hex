/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 17:12:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	put_sprite_to_image(t_env *env, t_sprite *sprite, int x, int y)
{
	int	i;
	int	j;
	int	*img_data =	env->win->img_data;
	int	width =		env->win->width;
	int	height =	env->win->height;

	i = 0;
	while (i < sprite->y)
	{
		j = 0;
		while (j < sprite->x)
		{
			if (((y + i) >= 0) && ((y + i) < height) && ((x + j) >= 0) && ((x + j) < width) && sprite->img_data[(sprite->x * i) + j] != 0)
				img_data[((y + i) * height) + (x + j)] = sprite->img_data[(sprite->x * i) + j];
			j++;
		}
		i++;
	}
}

void	draw_tile(t_env *env, int sprite_address, int label, int x, int y)
{
	int		tru_x;
	int		tru_y;
	char	point_str[20];

	tru_x = env->cam->x + ((x - y) * 45);
	tru_y = env->cam->y + ((x + y) * 22);
	put_sprite_to_image(env, env->sprite_bank[sprite_address], tru_x, tru_y);
	if (label)
	{
		sprintf(point_str, "(%d, %d)", x, y);
		mlx_string_put(env->win->mlx, env->win->win, tru_x + 33 - (ft_strlen(point_str) * 3), tru_y + 25, 0xFFFFFF, point_str);
	}
}

/*
** Facing:
** 1 - Up:		back
** 2 - Down:	front
** TODO:
** 3 - Left:	back flipped
** 4 - Right:	front flipped
*/

void	draw_pokemon(t_env *env, int number, int direction, int x, int y)
{
	int		tru_x;
	int		tru_y;

	tru_x = (env->cam->x + ((x - y) * 45)) - 15;
	tru_y = (env->cam->y + ((x + y) * 22)) - 45;
	if (direction == 1)
		put_sprite_to_image(env, env->poke_db[number]->sprite_f, tru_x, tru_y);
	else if (direction == 2)
		put_sprite_to_image(env, env->poke_db[number]->sprite_b, tru_x, tru_y);
	else
		throw_error("draw_pokemon: invalid direction");
	mlx_string_put(env->win->mlx, env->win->win, tru_x + 48 - (ft_strlen(env->poke_db[number]->name) * 3), tru_y + 80, 0xFFFFFF, env->poke_db[number]->name);
}

void	gen_view(t_env *env)
{
	clear_img(env->win);
	//Action
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			draw_tile(env, SPRITE_GRASS, 0, i, j);
			j++;
		}
		i++;
	}
	put_sprite_to_image(env, env->sprite_bank[SPRITE_CURSOR], env->mouse_x, env->mouse_y);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->win->img, 0, 0);

	// i = 0;
	// while (i < 10)
	// {
	// 	j = 0;
	// 	while (j < 10)
	// 	{
	// 		if (rand() % 2)
	// 			draw_pokemon(env, (rand() % POKEMON_TOTAL) + 1, 1, i, j);
	// 		j++;
	// 	}
	// 	i++;
	// }

	// //Hex Terrain Test Start
	// int counter = 0;
	// int	i;
	// int	j;
	// int	x;
	// int	y;
	// int	tiles_across;
	// int	center_x = 400;
	// int	top_y = 78;
	// i = 0;
	// while (i < 11)
	// {
	// 	if (i < 6)
	// 	{
	// 		tiles_across = i + 6;
	// 		x = center_x - (45 * i);
	// 		y = top_y + (22 * i);
	// 	}
	// 	else
	// 	{
	// 		tiles_across = 16 - i;
	// 		x = center_x - (45 * 5);
	// 		y = top_y + (22 * 5) + (44 * (i - 5));
	// 	}
	// 	j = 0;
	// 	while (j < tiles_across)
	// 	{
	// 		mlx_put_image_to_window(env->win->mlx, env->win->win, env->sprite_bank[SPRITE_GRASS]->img, x, y);
	// 		//COUNTER
	// 		mlx_string_put(env->win->mlx, env->win->win, x + 30, y + 25, 0xFFFFFF, ft_itoa(++counter));
	// 		//COUNTER
	// 		x += 45;
	// 		y += 22;
	// 		j++;
	// 	}
	// 	i++;
	// }
	// //Hex Terrain Test End

}
