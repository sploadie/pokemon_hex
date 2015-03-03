/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/03 19:08:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int				hex_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env			*env;
	static int		rolling = 0;
	char			str[200];
	int				temp_id;
	t_tile			*clicked_tile;

	env = env_ptr;
	if (button == 1)
	{
		temp_id = env->win->sprite_data[(y * env->win->width) + x];
		if (temp_id < 0) //Clicked on tile
		{
			clicked_tile = fetch_tile(env, temp_id);
			write(1, str, sprintf(str, "Mouse: Left Clicked on tile (%d, %d) @ (%d, %d)\n", clicked_tile->x, clicked_tile->y, x, y));
			if (env->selected_entity && clicked_tile->entity == env->selected_entity)
			{
				env->selected_entity->curr_sprite++;
				if (env->selected_entity->curr_sprite > 3)
					env->selected_entity->curr_sprite = 0;
				env->selected_entity = NULL;
			}
			else if (clicked_tile->entity)
			{
				write(1, str, sprintf(str, "Selected entity %d, named %s.\n", clicked_tile->entity->id, clicked_tile->entity->poke_data->name));
				env->selected_entity = clicked_tile->entity;
			}
			else if (env->selected_entity && tile_distance(env->selected_entity->tile, clicked_tile) == 1)
			{
				env->selected_entity->tile->entity = NULL;
				env->selected_entity->tile = clicked_tile;
				clicked_tile->entity = env->selected_entity;
				env->selected_entity = NULL;
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
