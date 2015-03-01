/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 19:21:50 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	put_sprite_to_image(t_env *env, t_sprite *sprite, int id, int x, int y)
{
	int	i;
	int	j;
	int	*img_data =		env->win->img_data;
	int	*sprite_data =	env->win->sprite_data;
	int	width =			env->win->width;
	int	height =		env->win->height;

	i = 0;
	while (i < sprite->y)
	{
		j = 0;
		while (j < sprite->x)
		{
			if (((y + i) >= 0) && ((y + i) < height) && ((x + j) >= 0) && ((x + j) < width) && sprite->img_data[(sprite->x * i) + j] != 0)
			{
				img_data[((y + i) * height) + (x + j)] = sprite->img_data[(sprite->x * i) + j];
				if (id)
					sprite_data[((y + i) * height) + (x + j)] =	id;
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_env *env)
{
	int			i;
	int			total;
	t_tile		**map;
	t_entity	**entities;
	t_sprite	**sprite_bank;

	map = env->map;
	entities = env->entities;
	sprite_bank = env->sprite_bank;
	total = MAP_WIDTH * MAP_HEIGHT;
	i = 0;
	while (i < total)
	{
		if (map[i]->type)
			put_sprite_to_image(env, sprite_bank[map[i]->type], map[i]->id, env->cam->x + map[i]->sprite_x, env->cam->y + map[i]->sprite_y);
		i++;
	}
	i = 0;
	while (i < total)
	{
		if (map[i]->entity_id)
			put_sprite_to_image(env, entities[map[i]->entity_id]->curr_sprite, map[i]->id, env->cam->x + map[i]->sprite_x - 15, env->cam->y + map[i]->sprite_y - 45);
		i++;
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

void	draw_pokemon(t_env *env, int number, int id, int direction, int x, int y)
{
	int		tru_x;
	int		tru_y;

	tru_x = (env->cam->x + ((x - y) * 45)) - 15;
	tru_y = (env->cam->y + ((x + y) * 22)) - 45;
	if (direction == 1)
		put_sprite_to_image(env, env->poke_db[number]->sprite_f, id, tru_x, tru_y);
	else if (direction == 2)
		put_sprite_to_image(env, env->poke_db[number]->sprite_b, id, tru_x, tru_y);
	else
		throw_error("draw_pokemon: invalid direction");
	mlx_string_put(env->win->mlx, env->win->win, tru_x + 48 - (ft_strlen(env->poke_db[number]->name) * 3), tru_y + 80, 0xFFFFFF, env->poke_db[number]->name);
}

void	gen_view(t_env *env)
{
	clear_img(env->win);
	//Action
	draw_map(env);
	put_sprite_to_image(env, env->sprite_bank[SPRITE_CURSOR], 0, env->mouse_x, env->mouse_y);
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
