/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:24:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/03 19:46:03 by tgauvrit         ###   ########.fr       */
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
		neoentities[i]->id = i;
		neoentities[i]->curr_sprite = 0;
		// neoentities[i]->x = 0;
		// neoentities[i]->y = 0;
		neoentities[i]->rand_x = 0;
		neoentities[i]->rand_y = 0;
		neoentities[i]->poke_data = NULL;
		neoentities[i]->tile = NULL;
		i++;
	}
	//TEST MAP
	i = 0;
	counter = 0;
	while (i < 20)//Modify at will
	{
		j = 0;
		while (j < 20)//Modify at will
		{
			if (counter < MAX_ENTITIES - 1 && rand() % 4 == 3)
			{
				counter++;
				neoentities[counter]->curr_sprite = rand() % 4;
				neoentities[counter]->poke_data = env->poke_db[(rand() % POKEMON_TOTAL) + 1];
				neoentities[counter]->tile = fetch_tile_at(env, j, i);
				neoentities[counter]->tile->entity = neoentities[counter];
			}
			j++;
		}
		i++;
	}
	//TEST MAP
	return (neoentities);
}
