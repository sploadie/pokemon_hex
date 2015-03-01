/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:24:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 19:34:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_entity	**gen_entities(t_env *env)
{
	t_entity	**neoentities;
	int			i;
	int			j;
	int			counter;

	(void)env;
	neoentities = check_malloc(malloc(sizeof(t_entity *) * (MAX_ENTITIES)));
	i = 0;
	while (i < MAP_HEIGHT)
	{
		neoentities[i] = check_malloc(malloc(sizeof(t_entity)));
		neoentities[i]->curr_sprite = NULL;
		neoentities[i]->map_index = 0;
		i++;
	}
	//TEST MAP
	i = 0;
	counter = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (rand() % 2)
			{
				counter++;
				neoentities[counter]->curr_sprite = env->poke_db[(rand() % POKEMON_TOTAL) + 1]->sprite_f;
				neoentities[counter]->map_index = (i * MAP_WIDTH) + j;
				env->map[(i * MAP_WIDTH) + j]->entity_id = counter;
			}
			j++;
		}
		i++;
	}
	//TEST MAP
	return (neoentities);
}
