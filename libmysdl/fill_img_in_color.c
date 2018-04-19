/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_in_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:35:44 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 19:02:22 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

void	fill_img_in_color(t_image *img, uint32_t color)
{
	int				i;
	int				max;

	if (img->size->x == 0)
		max = img->size->y;
	else if (img->size->y == 0)
		max = img->size->x;
	else 
		max = img->size->x * img->size->y;
	i = 0;
	while (i < max)
	{
		img->tab_pxl[i] = color;
		i++;
	}
}
