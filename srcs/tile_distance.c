/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:37:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/08 13:13:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int	tile_distance(t_tile *tile_a, t_tile *tile_b)
{
	int	distance;
	int	diff_x;
	int	diff_y;
	int	abs_diff_x;
	int	abs_diff_y;

	distance = 0;
	diff_x		= tile_a->x - tile_b->x;
	diff_y		= tile_a->y - tile_b->y;
	abs_diff_x	= abs(diff_x);
	abs_diff_y	= abs(diff_y);
	if ((diff_x < 0 && diff_y > 0) || (diff_x > 0 && diff_y < 0))
		distance += ((abs_diff_x < abs_diff_y) ? abs_diff_x : abs_diff_y);
	return ((abs_diff_x > abs_diff_y) ? (distance + abs_diff_x) : (distance + abs_diff_y));
}

// int	tile_distance(t_tile *tile_a, t_tile *tile_b)
// {
// 	int	x_distance;
// 	int	y_distance;

// 	x_distance = abs(tile_a->x - tile_b->x);
// 	y_distance = abs(tile_a->y - tile_b->y);
// 	return ((x_distance > y_distance) ? x_distance : y_distance);
// }
