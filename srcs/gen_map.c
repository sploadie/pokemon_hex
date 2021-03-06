/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:37:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/09 12:41:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_tile	*gen_map(t_env *env)
{
	t_tile	*neomap;
	int		counter;
	int		i;
	int		j;

	(void)env;
	neomap = check_malloc(malloc(sizeof(t_tile) * (MAP_WIDTH * MAP_HEIGHT)));
	counter = 0;
	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			neomap[counter].type = 0;
			neomap[counter].id = (counter + 1) * -1;
			neomap[counter].x = j;
			neomap[counter].y = i;
			neomap[counter].sprite_x = ((j - i) * 45);
			neomap[counter].sprite_y = ((j + i) * 22);
			neomap[counter].entity = NULL;
			counter++;
			j++;
		}
		i++;
	}
	//TEST MAP
	i = 0;
	while (i < 20)//Modify at will
	{
		j = 0;
		while (j < 20)//Modify at will
		{
			neomap[(i * MAP_WIDTH) + j].type = SPRITE_GRASS;
			j++;
		}
		i++;
	}
	//TEST MAP
	return (neomap);
}
