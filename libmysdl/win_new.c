/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:15:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 21:09:36 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

t_win		*win_new(t_point size, char *title)
{
	t_win		*info;

	info = (t_win*)malloc(sizeof(t_win));
	if (!(info->ptr = SDL_CreateWindow(title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			size.x,
			size.y,
			SDL_WINDOW_SHOWN | SDL_WINDOW_MINIMIZED)))
		return (NULL);
	if (!(info->size = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	info->imgs = NULL;
	info->ren = NULL;
	info->size->x = size.x;
	info->size->y = size.y;
	return (info);
}