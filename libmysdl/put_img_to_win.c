/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:34:17 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 17:38:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

void	put_img_to_win(t_image *img, SDL_Renderer *ren)
{
	SDL_UpdateTexture(img->tex, NULL, img->tab_pxl, img->size->x * sizeof(uint32_t));
	SDL_RenderCopy(ren, img->tex, NULL, NULL);
	SDL_RenderPresent(ren);
}
