/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 17:42:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int		hex_loop_hook(void *env_ptr)
{
	static int		displaying = 0;
	t_env			*env;

	env = env_ptr;
	if (displaying == 1)
		return (0);
	if (!env->update)
		return (0);
	displaying = 1;
	env->update = 0;
	ft_putstr("\033[2K\rRedrawing Image... ");
	gen_view(env);
	ft_putstr(" done.");
	displaying = 0;
	return (0);
}
