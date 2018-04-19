/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:44:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 19:44:40 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"
#include <stdlib.h>

t_texture		*texture_new(t_point size, SDL_Renderer *ren)
{
	t_texture			*tex;

	if ((tex = (t_texture*)malloc(sizeof(t_texture))) == NULL)
		return (NULL);
	if ((tex->size = (t_point*)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	if (!(tex->tab_pxl = (uint32_t*)malloc(sizeof(uint32_t) * size.x * size.y)))
		return (NULL);
	tex->size->x = size.x;
	tex->size->y = size.y;
	tex->sdl_tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STATIC, size.x, size.y);
	return (tex);
}
