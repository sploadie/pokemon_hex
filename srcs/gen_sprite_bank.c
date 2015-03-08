/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sprite_bank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:01:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/08 12:29:49 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_sprite	*gen_sprite_bank(void *mlx)
{
	t_sprite	*neobank;
	int			temp;

	neobank = check_malloc(malloc(sizeof(t_sprite) * SPRITE_BANK_SIZE));
	/* SPRITE_CURSOR */
	neobank[SPRITE_CURSOR].img = mlx_xpm_file_to_image(mlx, "./img/xpm-menu/cursor.xpm", &(neobank[SPRITE_CURSOR].width), &(neobank[SPRITE_CURSOR].height));
	if (neobank[SPRITE_CURSOR].img == NULL)
		throw_error("gen_sprite_bank: SPRITE_CURSOR");
	neobank[SPRITE_CURSOR].img_data = (int *)mlx_get_data_addr(neobank[SPRITE_CURSOR].img, &temp, &temp, &temp);
	/* SPRITE_GRASS */
	neobank[SPRITE_GRASS].img = mlx_xpm_file_to_image(mlx, "./img/xpm-menu/grass.xpm", &(neobank[SPRITE_GRASS].width), &(neobank[SPRITE_GRASS].height));
	if (neobank[SPRITE_GRASS].img == NULL)
		throw_error("gen_sprite_bank: SPRITE_GRASS");
	neobank[SPRITE_GRASS].img_data = (int *)mlx_get_data_addr(neobank[SPRITE_GRASS].img, &temp, &temp, &temp);
	/* SPRITE_SELECT */
	neobank[SPRITE_SELECT].img = mlx_xpm_file_to_image(mlx, "./img/xpm-menu/select_small.xpm", &(neobank[SPRITE_SELECT].width), &(neobank[SPRITE_SELECT].height));
	if (neobank[SPRITE_SELECT].img == NULL)
		throw_error("gen_sprite_bank: SPRITE_SELECT");
	neobank[SPRITE_SELECT].img_data = (int *)mlx_get_data_addr(neobank[SPRITE_SELECT].img, &temp, &temp, &temp);
	return (neobank);
}
