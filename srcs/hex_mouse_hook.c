/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 19:15:05 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int				hex_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env			*env;
	static int		rolling = 0;
	char			str[200];
	int				temp_id;

	env = env_ptr;
	if (button == 1)
	{
		temp_id = env->win->sprite_data[(y * env->win->width) + x];
		if (temp_id < 0)
			write(1, str, sprintf(str, "Mouse: Left Clicked on tile (%d, %d) @ (%d, %d)\n", env->map[(temp_id * -1) - 1]->x, env->map[(temp_id * -1) - 1]->y, x, y));
		else
			write(1, str, sprintf(str, "Mouse: Left Click @ (%d, %d)\n", x, y));
		//Action
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
