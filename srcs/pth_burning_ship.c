/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_burning_ship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:57:35 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 17:10:02 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

/*
** c et z sont des points et c.x représente la partie réel
** c.y = partie imaginaire
** le nb max d'itération definira la netteté de la fractale
** pour zoomer, il faudra augmenter la netteté
*/

static int		i_value(t_point i, t_ptfl z, t_ptfl c)
{
	float		swap;

	i.x = 0;
	while (i.x < i.y && (((z.x * z.x) + (z.y * z.y)) < 4.0))
	{
		swap = z.x;
		z.x = fabsf((((z.x * z.x) - (z.y * z.y)) + c.x));
		z.y = fabsf(((2 * swap * z.y) + c.y));
		i.x = i.x + 1;
	}
	return (i.x);
}

void			*pth_burning_ship(void *pth_param)
{
	t_ptfl			z;
	t_ptfl			c;
	t_point			i;
	t_pth_param		pth;

	pth = *(t_pth_param*)pth_param;
	i = pt_set(0, pth.param->imax);
	pth.space.position = ptfl_bc(pth.space.position, '/', pth.space.zoom);
	while (pth.crd.x < pth.x_max)
	{
		c.x = (pth.crd.x * pth.lim.incr.x) + pth.lim.min.x;
		c.y = (pth.crd.y * pth.lim.incr.y) + pth.lim.min.y;
		z.x = (pth.crd.x * pth.lim.incr.x) + pth.lim.min.x;
		z.y = (pth.crd.y * pth.lim.incr.y) + pth.lim.min.y;
		i.x = i_value(i, z, c);
		color_with_i(i, pth.param, pth.img, pth.crd);
		pth.crd = pt_ypluseg(pth.crd, 0, pth.param->win->size.y);
	}
	return (NULL);
}
