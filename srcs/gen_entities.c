/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:24:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/02 11:29:46 by tgauvrit         ###   ########.fr       */
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
	while (i < MAX_ENTITIES)
	{
		neoentities[i] = check_malloc(malloc(sizeof(t_entity)));
		neoentities[i]->curr_sprite = NULL;
		neoentities[i]->map_index = 0;
		neoentities[i]->rand_x = 0;
		neoentities[i]->rand_y = 0;
		i++;
	}
	//TEST MAP
	i = 0;
	counter = 0;
	int poke_id;
	while (i < 20)//Modify at will
	{
		j = 0;
		while (j < 20)//Modify at will
		{
			if (counter < MAX_ENTITIES - 1 && rand() % 4 == 3)
			{
				counter++;
				poke_id = (rand() % POKEMON_TOTAL) + 1;
				neoentities[counter]->curr_sprite = env->poke_db[poke_id]->sprite_f;
				neoentities[counter]->poke_id = poke_id;
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
