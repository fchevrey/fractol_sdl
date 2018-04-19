/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_to_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:10:54 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 16:44:17 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

void		pt_to_img(t_point pt, t_image *img, uint32_t color)
{
	int				to_color;

	if (!img)
		return ;
	if (pt.x >= img->size->x || pt.y >= img->size->y || pt.x < 0 || pt.y < 0)
		return ;
	to_color = (pt.x + (pt.y * img->size->x));
	//ft_putnbrnl(to_color);
	img->tab_pxl[to_color] = color;
}
