/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 14:35:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int				hex_mouse_hook(int button, int x, int y, void *env_ptr)
{
	t_env			*env;
	static int		rolling = 0;

	env = env_ptr;
	if (button == 1)
	{
		ft_putstr("Mouse: Left Click @ x: ");
		ft_putnbr(x);
		write(1, ", y: ", 5);
		ft_putnbr(y);
		write(1, "\n", 1);
		//Action
	}
	else if (rolling == 0)
	{
		rolling = 1;
		if (button == 4)
		{
			ft_putstr("Scroll Down ");
			//Action
		}
		else if (button == 5)
		{
			ft_putstr("Scroll Up ");
			//Action
		}
		else if (button == 6)
		{
			ft_putstr("Scroll Right ");
			//Action
		}
		else if (button == 7)
		{
			ft_putstr("Scroll Left ");
			//Action
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
	//env->update = 1;
	return (0);
}
