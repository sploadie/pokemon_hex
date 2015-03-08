/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/08 17:12:54 by tgauvrit         ###   ########.fr       */
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
	while (i < sprite->height)
	{
		j = 0;
		while (j < sprite->width)
		{
			if (((y + i) >= 0) && ((y + i) < height) && ((x + j) >= 0) && ((x + j) < width) && sprite->img_data[(sprite->width * i) + j] != 0)
			{
				img_data[((y + i) * width) + (x + j)] = sprite->img_data[(sprite->width * i) + j];
				if (id)
					sprite_data[((y + i) * width) + (x + j)] =	id;
			}
			j++;
		}
		i++;
	}
}

void	select_markers(t_env *env)
{
	t_tile	*main_tile;
	t_tile	*temp_tile;
	int		i;
	int		j;

	if (!env->selected_entity)
		return ;
	main_tile = env->selected_entity->tile;
	i = MOVEMENT * -1;
	while (i <= MOVEMENT)
	{
		j = MOVEMENT * -1;
		while (j <= MOVEMENT)
		{
			if (!(i == 0 && j == 0)
				&& (temp_tile = fetch_tile_at(env, main_tile->x + i, main_tile->y + j))
				&& temp_tile->type != 0
				&& tile_distance(main_tile, temp_tile) <= MOVEMENT)
			{
				put_sprite_to_image(env,
					&env->sprite_bank[SPRITE_SELECT],
					temp_tile->id,
					env->cam->x + temp_tile->sprite_x + 12,
					env->cam->y + temp_tile->sprite_y - 5
				);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_env *env)
{
	int				i;
	int				total;
	t_tile			*map;
	t_sprite		*sprite_bank;
	static clock_t	wiggle = 0;

	map = env->map;
	sprite_bank = env->sprite_bank;
	total = MAP_WIDTH * MAP_HEIGHT;
	/* Tiles */
	i = 0;
	while (i < total)
	{
		if (map[i].type)
		{
			put_sprite_to_image(env, &sprite_bank[map[i].type], map[i].id, env->cam->x + map[i].sprite_x, env->cam->y + map[i].sprite_y);
		}
		i++;
	}
	/* Selection Markers */
	if (((clock() / (CLOCKS_PER_SEC / 4)) % 4) > 1)
		select_markers(env);
	/* Entities */
	i = 0;
	while (i < total)
	{
		if (map[i].entity)
		{
			if (clock() > wiggle)
			{
				if (map[i].entity->id == 1)	/* Player */
				{
					map[i].entity->curr_sprite = (map[i].entity->curr_sprite + 2) % 4;
				}
				else						/* Pokemon */
				{
					if (map[i].entity->rand_y != 0)
						map[i].entity->rand_y = 0;
					else if (rand() % 2)
						map[i].entity->rand_y = -2;
				}
			}
			put_sprite_to_image(env,
				map[i].entity->poke_data->sprite[map[i].entity->curr_sprite],
				map[i].id,
				env->cam->x + map[i].sprite_x - 15 + map[i].entity->rand_x,
				env->cam->y + map[i].sprite_y - 45 + map[i].entity->rand_y
			);
		}
		i++;
	}
	if (clock() > wiggle)
		wiggle = clock() + CLOCKS_PER_HALF;
}

void	draw_hp_bar(t_env *env)
{
	t_tile		*tile;
	t_entity	*entity;

	if ((tile = fetch_tile(env, env->win->sprite_data[(env->mouse_y * env->win->width) + env->mouse_x])) == NULL)
		return ;
	if ((entity = tile->entity) == NULL)
		return ;
	put_sprite_to_image(env,
		&env->sprite_bank[SPRITE_HP_BAR],
		0,
		env->cam->x + tile->sprite_x - 15,
		env->cam->y + tile->sprite_y + 31
	);
	if (entity->stats.hp > 0)
		env->sprite_bank[SPRITE_HP_FILL].width = 80 / ((entity->poke_data->stats.hp * 80) / (entity->stats.hp * 80));
	else
		env->sprite_bank[SPRITE_HP_FILL].width = 1;
	put_sprite_to_image(env,
		&env->sprite_bank[SPRITE_HP_FILL],
		0,
		env->cam->x + tile->sprite_x - 15 + 7,
		env->cam->y + tile->sprite_y + 31 + 2
	);
}

void	gen_view(t_env *env)
{
	clear_img(env->win);
	//Action
	draw_map(env);
	// select_markers(env);
	draw_hp_bar(env);
	put_sprite_to_image(env, &env->sprite_bank[SPRITE_CURSOR], 0, env->mouse_x, env->mouse_y);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->win->img, 0, 0);
	mlx_do_sync(env->win->mlx);

	// //DEBUG
	// char str[200];
	// write(1, str, sprintf(str, "Mouse: (%d, %d)", env->mouse_x, env->mouse_y));
	// //DEBUG

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
