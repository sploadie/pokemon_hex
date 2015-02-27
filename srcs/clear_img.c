/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/27 17:19:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	gen_clear_img(t_win *win)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		*clear_img_data;

	width = win->width;
	height = win->height;
	win->clear_img = mlx_new_image(win->mlx, width, height);
	clear_img_data = (int *)mlx_get_data_addr(win->clear_img,
									&(win->img_bits_per_pixel),
									&(win->img_size_line),
									&(win->img_endian));
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			clear_img_data[(i * width) + (j++)] = 0x0;
		i++;
	}
}

void	clear_img(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->clear_img, 0, 0);
}
