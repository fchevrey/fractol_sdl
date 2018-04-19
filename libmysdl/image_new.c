/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:44:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 21:12:02 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"
#include <stdlib.h>

t_image		*image_new(t_point size, SDL_Renderer *ren)
{
	t_image			*img;

	if ((img = (t_image*)malloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->size = (t_point*)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	if (!(img->tab_pxl = (uint32_t*)malloc(sizeof(uint32_t) * size.x * size.y)))
		return (NULL);
	img->size->x = size.x;
	img->size->y = size.y;
	img->tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STATIC, size.x, size.y);
	return (img);
}
