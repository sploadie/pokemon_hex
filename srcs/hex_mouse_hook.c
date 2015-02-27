/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/27 16:38:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int				fdf_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env			*env;
	static int		rolling = 0;

	env = env_ptr;
	if (button == 1)
	{
		//Action
		env->update = 1;
	}
	else if (rolling == 0)
	{
		rolling = 1;
		if (button == 4)
		{
			//Action
		}
		else if (button == 5)
		{
			//Action
		}
		else if (button == 6)
		{
			//Action
		}
		else if (button == 7)
		{
			//Action
		}
		rolling = 0;
		env->update = 1;
	}
	return (0);
}

int				fdf_mouse_move_hook(int x, int y, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	(void)x;
	(void)y;
	(void)env;
	//env->update = 1;
	return (0);
}
