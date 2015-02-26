/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 17:04:17 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/02/26 17:43:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pokemon_hex.h"

void	*check_malloc(void *ret)
{
	if (ret)
		return (ret);
	throw_error(NULL);
	return (NULL);
}
