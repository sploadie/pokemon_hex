/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:38:39 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/08 11:42:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_tile	*fetch_tile(t_env *env, int tile_id)
{
	tile_id = (tile_id * -1) - 1;
	if (tile_id < 0 && tile_id >= MAP_WIDTH * MAP_HEIGHT)
		throw_error("fetch_tile: invalid id");
	return (&env->map[tile_id]);
}

t_tile	*fetch_tile_at(t_env *env, int x, int y)
{
	if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
		return (NULL);
	return (&env->map[(y * MAP_WIDTH) + x]);
}
