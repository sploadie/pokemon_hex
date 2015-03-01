/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 20:46:06 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int				hex_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env			*env;
	static int		rolling = 0;
	char			str[200];
	int				temp_id;
	int				map_index;
	t_entity		*curr_entity;
	t_tile			*curr_tile;
	t_tile			*clicked_tile;

	env = env_ptr;
	if (button == 1)
	{
		temp_id = env->win->sprite_data[(y * env->win->width) + x];
		if (temp_id < 0)
		{
			map_index = (temp_id * -1) - 1;
			clicked_tile = env->map[map_index];
			write(1, str, sprintf(str, "Mouse: Left Clicked on tile (%d, %d) @ (%d, %d)\n", clicked_tile->x, clicked_tile->y, x, y));
			if (clicked_tile->entity_id && clicked_tile->entity_id == env->selected_entity)
			{
				curr_entity = env->entities[env->selected_entity];
				if (curr_entity->curr_sprite == env->poke_db[curr_entity->poke_id]->sprite_f)
					curr_entity->curr_sprite = env->poke_db[curr_entity->poke_id]->sprite_b;
				else
					curr_entity->curr_sprite = env->poke_db[curr_entity->poke_id]->sprite_f;
			}
			else if (clicked_tile->entity_id)
			{
				write(1, str, sprintf(str, "Selected entity %d, named %s.\n", clicked_tile->entity_id, env->poke_db[env->entities[clicked_tile->entity_id]->poke_id]->name));
				env->selected_entity = clicked_tile->entity_id;
			}
			else if (env->selected_entity)
			{
				curr_entity = env->entities[env->selected_entity];
				curr_tile = env->map[curr_entity->map_index];
				curr_tile->entity_id = 0;
				curr_entity->map_index = map_index;
				clicked_tile->entity_id = env->selected_entity;
				env->selected_entity = 0;
			}
		}
		else
			write(1, str, sprintf(str, "Mouse: Left Click @ (%d, %d)\n", x, y));
	}
	else if (rolling == 0)
	{
		rolling = 1;
		if (button == 4)
		{
			// ft_putstr("Scroll Down ");
			env->cam->y--;
		}
		else if (button == 5)
		{
			// ft_putstr("Scroll Up ");
			env->cam->y++;
		}
		else if (button == 6)
		{
			// ft_putstr("Scroll Right ");
			env->cam->x--;
		}
		else if (button == 7)
		{
			// ft_putstr("Scroll Left ");
			env->cam->x++;
		}
		rolling = 0;
	}
	env->update = 1;
	return (0);
}

int				hex_mouse_move_hook(int x, int y, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	env->mouse_x = x;
	env->mouse_y = y;
	// env->update = 1;//FIXME?
	return (0);
}
