/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:26:00 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/09 14:26:11 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	put_sprite_to_image(t_env *env, t_sprite *sprite, int id, int x, int y)
{
	int	i;
	int	j;
	int	*img_data =		env->win->img_data;
	int	*sprite_data =	env->win->sprite_data;
	int	width =			env->win->width;
	int	height =		env->win->height;

	i = 0;
	while (i < sprite->height)
	{
		j = 0;
		while (j < sprite->width)
		{
			if (((y + i) >= 0) && ((y + i) < height) && ((x + j) >= 0) && ((x + j) < width) && sprite->img_data[(sprite->width * i) + j] != 0)
			{
				img_data[((y + i) * width) + (x + j)] = sprite->img_data[(sprite->width * i) + j];
				if (id)
					sprite_data[((y + i) * width) + (x + j)] =	id;
			}
			j++;
		}
		i++;
	}
}
