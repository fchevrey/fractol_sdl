/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:08:14 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 14:51:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"
#include <stdlib.h>

void		free_img(t_image **img)
{
	if (!img || !*img)
		return ;
	free((*img)->size);
	free((*img)->tab_pxl);
	(*img)->size = NULL;
	(*img)->tab_pxl = NULL;
	SDL_DestroyTexture((*img)->tex);
	free(*img);
	*img = NULL;
}
