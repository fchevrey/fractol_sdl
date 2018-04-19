/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:56:00 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 16:53:51 by fchevrey         ###   ########.fr       */
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

void			burning_ship(t_param *param, t_image *img, t_limits lim,
		t_space space)
{
	t_ptfl			z;
	t_ptfl			c;
	t_point			i;
	t_point			crd;

	i = pt_set(0, param->imax);
	crd = pt_set(0, 0);
	space.position = ptfl_bc(space.position, '/', space.zoom);
	while (crd.x < param->win->size.x)
	{
		c.x = (crd.x * lim.incr.x) + lim.min.x;
		c.y = (crd.y * lim.incr.y) + lim.min.y;
		z.x = (crd.x * lim.incr.x) + lim.min.x;
		z.y = (crd.y * lim.incr.y) + lim.min.y;
		i.x = i_value(i, z, c);
		color_with_i(i, param, img, crd);
		crd = pt_ypluseg(crd, 0, param->win->size.y);
	}
}
