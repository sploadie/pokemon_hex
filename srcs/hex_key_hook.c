/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 14:15:57 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int		hex_key_hook(int keycode, void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	if (keycode == 65307)
	{
		ft_putstr("Esc\n");
		exit(0);
	}
	else if (keycode == 65361)
	{
		ft_putstr("Arrow Left\n");
		//Action
	}
	else if (keycode == 65362)
	{
		ft_putstr("Arrow Up\n");
		//Action
	}
	else if (keycode == 65363)
	{
		ft_putstr("Arrow Right\n");
		//Action
	}
	else if (keycode == 65364)
	{
		ft_putstr("Arrow Down\n");
		//Action
	}
	else if (keycode == 59)
	{
		ft_putstr("Key ;\n");
		//Action
	}
	else if (keycode == 47)
	{
		ft_putstr("Key /\n");
		//Action
	}
	else if (keycode == 113)
	{
		ft_putstr("Key Q\n");
		//Action
	}
	else if (keycode == 119)
	{
		ft_putstr("Key W\n");
		//Action
	}
	else if (keycode == 101)
	{
		ft_putstr("Key E\n");
		//Action
	}
	else if (keycode == 97)
	{
		ft_putstr("Key A\n");
		//Action
	}
	else if (keycode == 115)
	{
		ft_putstr("Key S\n");
		//Action
	}
	else if (keycode == 100)
	{
		ft_putstr("Key D\n");
		//Action
	}
	else if (keycode == 45)
	{
		ft_putstr("Key -/_\n");
		//Action
	}
	else if (keycode == 61)
	{
		ft_putstr("Key =/+\n");
		//Action
	}
	else if (keycode == 49)
	{
		ft_putstr("Key 1\n");
		//Action
	}
	else if (keycode == 50)
	{
		ft_putstr("Key 2\n");
		//Action
	}
	else if (keycode == 51)
	{
		ft_putstr("Key 3\n");
		//Action
	}
	else if (keycode == 52)
	{
		ft_putstr("Key 4\n");
		//Action
	}
	else
	{
		write(1, "Key: ", 5);
		ft_putnbr(keycode);
		write(1, "\n", 1);
		return(0);
	}
	env->update = 1;
	return (0);
}
