/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_expose_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/28 14:16:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

int		hex_expose_hook(void *env_ptr)
{
	t_env	*env;

	env = env_ptr;
	ft_putstr("Expose hook hit: Generating image...\n");
	gen_view(env);
	return (0);
}
