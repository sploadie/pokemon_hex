/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/09 15:31:49 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	add_text(t_env *env, char *str, int x, int y, int color, void (*to_free)())
{
	t_mlx_text	*neotext;

	neotext = check_malloc(malloc(sizeof(t_mlx_text)));
	neotext->str = str;
	neotext->x = x;
	neotext->y = y;
	neotext->color = color;
	neotext->to_free = to_free;
	neotext->next = env->mlx_text;
	env->mlx_text = neotext;
}

void	draw_text_to_image(t_env *env)
{
	t_mlx_text	*text;
	t_mlx_text	*temp;

	text = env->mlx_text;
	while (text != NULL)
	{
		;//put string to window, then free, then move forward;
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
	// if (((clock() / (CLOCKS_PER_SEC / 4)) % 4) > 1)
	select_markers(env);
	/* Entities */
	i = 0;
	while (i < total)
	{
		if (map[i].entity)
		{
			if (clock() > wiggle)
			{
				if (map[i].entity->rand_y != 0)
					map[i].entity->rand_y = 0;
				else if (rand() % 2)
					map[i].entity->rand_y = -2;
				/* Animated Player */
				// if (map[i].entity->id == 1)	/* Player */
				// {
				// 	map[i].entity->curr_sprite = (map[i].entity->curr_sprite + 2) % 4;
				// }
				// else						/* Pokemon */
				// {
				// 	if (map[i].entity->rand_y != 0)
				// 		map[i].entity->rand_y = 0;
				// 	else if (rand() % 2)
				// 		map[i].entity->rand_y = -2;
				// }
				/* - */
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
		env->sprite_bank[SPRITE_HP_FILL].width = (int)floor(((double)entity->stats.hp / (double)entity->poke_data->stats.hp) * 80.0f);
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
	draw_hp_bar(env);
	put_sprite_to_image(env, &env->sprite_bank[SPRITE_CURSOR], 0, env->mouse_x, env->mouse_y);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->win->img, 0, 0);
	mlx_do_sync(env->win->mlx);
}
