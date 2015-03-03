/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:37:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/03 16:49:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int	tile_distance(t_tile *tile_a, t_tile *tile_b)
{
	int	x_distance;
	int	y_distance;

	x_distance = abs(tile_a->x - tile_b->x);
	y_distance = abs(tile_a->y - tile_b->y);
	return ((x_distance > y_distance) ? x_distance : y_distance);
}
