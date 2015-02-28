/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sprite_bank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:01:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 19:14:20 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_sprite	**gen_sprite_bank(void *mlx)
{
	t_sprite	**neobank;

	neobank = check_malloc(malloc(sizeof(t_sprite *) * SPRITE_BANK_SIZE));
	/* SPRITE_CURSOR */
	neobank[SPRITE_CURSOR] = check_malloc(malloc(sizeof(t_sprite)));
	neobank[SPRITE_CURSOR]->img = mlx_xpm_file_to_image(mlx, "./img/xpm-menu/cursor.xpm", &(neobank[SPRITE_CURSOR]->x), &(neobank[SPRITE_CURSOR]->y));
	if (neobank[SPRITE_CURSOR]->img == NULL)
		throw_error("gen_sprite_bank: SPRITE_CURSOR");
	/* SPRITE_GRASS */
	neobank[SPRITE_GRASS] = check_malloc(malloc(sizeof(t_sprite)));
	neobank[SPRITE_GRASS]->img = mlx_xpm_file_to_image(mlx, "./img/xpm-menu/grass.xpm", &(neobank[SPRITE_GRASS]->x), &(neobank[SPRITE_GRASS]->y));
	if (neobank[SPRITE_GRASS]->img == NULL)
		throw_error("gen_sprite_bank: SPRITE_GRASS");
	return (neobank);
}
