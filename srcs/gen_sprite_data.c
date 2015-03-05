/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sprite_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:35:46 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/03/05 16:27:48 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	gen_sprite_data(t_win *win)
{
	win->sprite_data = check_malloc(malloc((win->width * win->height) * sizeof(int)));
	ft_bzero(win->sprite_data, (win->width * win->height) * sizeof(int));
}
