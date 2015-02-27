/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_mlx_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/27 17:08:36 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

t_win	*gen_mlx_window(void *mlx, char *title, int x, int y)
{
	t_win	*neowin;

	if (!mlx)
		throw_error(NULL);
	neowin = check_malloc(malloc(sizeof(t_win)));
	neowin->win = mlx_new_window(mlx, x, y, title);
	if (!neowin->win)
		throw_error(NULL);
	neowin->mlx = mlx;
	neowin->title = title;
	if (x > INT_MAX)
		throw_error("gen_mlx_window");
	neowin->width = x;
	if (y > INT_MAX)
		throw_error("gen_mlx_window");
	neowin->height = y;
	return (neowin);
}
