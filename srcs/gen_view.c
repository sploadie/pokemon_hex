/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 19:20:18 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	gen_view(t_env *env)
{
	clear_img(env->win);
	//Action
	printf("%d, %d\n", env->sprite_bank[SPRITE_GRASS]->x, env->sprite_bank[SPRITE_GRASS]->y);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->sprite_bank[SPRITE_GRASS]->img, 100, 100);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->sprite_bank[SPRITE_GRASS]->img, env->mouse_x, env->mouse_y);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->sprite_bank[SPRITE_CURSOR]->img, env->mouse_x, env->mouse_y);
	mlx_put_image_to_window(env->win->mlx, env->win->win, env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f, rand() % (env->win->width - POKEMON_SPRITE_SIZE), rand() % (env->win->height - POKEMON_SPRITE_SIZE));
	// mlx_put_image_to_window(env->win->mlx, env->win->win, env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f, rand() % (env->win->width - POKEMON_SPRITE_SIZE), rand() % (env->win->height - POKEMON_SPRITE_SIZE));
	// mlx_put_image_to_window(env->win->mlx, env->win->win, env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f, rand() % (env->win->width - POKEMON_SPRITE_SIZE), rand() % (env->win->height - POKEMON_SPRITE_SIZE));
	// mlx_put_image_to_window(env->win->mlx, env->win->win, env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f, rand() % (env->win->width - POKEMON_SPRITE_SIZE), rand() % (env->win->height - POKEMON_SPRITE_SIZE));
	// mlx_put_image_to_window(env->win->mlx, env->win->win, env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f, rand() % (env->win->width - POKEMON_SPRITE_SIZE), rand() % (env->win->height - POKEMON_SPRITE_SIZE));
}
