/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/01 17:07:40 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	gen_clear_img(t_win *win)
{
	int				i;
	int				j;
	int				width;
	int				height;
	int				*clear_img_data;

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

	// //TESTING START
	// int temp;
	// char str[20];
	// mlx_get_data_addr(win->clear_img, &i, &j, &temp);
	// write(1, str, sprintf(str, "%x %x %x\n", i, j, temp));
	// i = 0;
	// j = 0;
	// int *img_data = (int *)mlx_get_data_addr(win->clear_img, &j, &j, &j);
	// while (i < height)
	// {
	// 	j = 0;
	// 	while (j < width)
	// 	{
	// 		ft_putnbr(img_data[(i * width) + (j)]);
	// 		write(1, " ", 1);
	// 		j++;
	// 	}
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// //TESTING END
}

void	clear_img(t_win *win)
{
	bzero(win->img_data, (win->width * win->height) * sizeof(int));
	// mlx_put_image_to_window(win->mlx, win->win, win->clear_img, 0, 0);
}
