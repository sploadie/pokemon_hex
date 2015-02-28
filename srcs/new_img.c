/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:57:43 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 14:31:11 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	new_img(t_win *win)
{
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->img_bits_per_pixel = 0;
	win->img_size_line = 0;
	win->img_endian = 0;
	win->img_data = (int *)mlx_get_data_addr(win->img,
									&(win->img_bits_per_pixel),
									&(win->img_size_line),
									&(win->img_endian));
	ft_putstr("img_bits_per_pixel: ");
	ft_putnbr(win->img_bits_per_pixel);
	ft_putstr("\nimg_endian: ");
	ft_putnbr(win->img_endian);
	ft_putstr("\nimg_size_line: ");
	ft_putnbr(win->img_size_line);
	write(1, "\n", 1);
}
