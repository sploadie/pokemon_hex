/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 14:34:16 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	gen_view(t_env *env)
{
	//clear_img(env->win);
	//Action
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f, rand() % (env->win->width - POKEMON_SPRITE_SIZE), rand() % (env->win->height - POKEMON_SPRITE_SIZE));
}
