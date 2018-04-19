/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:18:15 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 18:31:33 by fchevrey         ###   ########.fr       */
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

static int		i_value(t_point i, t_ptdb z, t_ptdb c)
{
	double		swap;

	i.x = 0;
	while (i.x < i.y && (((z.x * z.x) + (z.y * z.y)) < 4.0))
	{
		swap = z.x;
		z.x = fabs((((z.x * z.x) - (z.y * z.y)) + c.x));
		z.y = fabs(((2 * swap * z.y) + c.y));
		i.x = i.x + 1;
	}
	return (i.x);
}

void			burning_ship_db(t_param *param, t_image *img, t_limits_db lim,
		t_space_db space)
{
	t_ptdb			z;
	t_ptdb			c;
	t_point			i;
	t_point			crd;

	i = pt_set(0, param->imax);
	crd = pt_set(0, 0);
	space.position = ptdb_bc(space.position, '/', space.zoom);
	while (crd.x < param->win->size->x)
	{
		c.x = (crd.x * lim.incr.x) + lim.min.x;
		c.y = (crd.y * lim.incr.y) + lim.min.y;
		z.x = (crd.x * lim.incr.x) + lim.min.x;
		z.y = (crd.y * lim.incr.y) + lim.min.y;
		i.x = i_value(i, z, c);
		color_with_i(i, param, img, crd);
		crd = pt_ypluseg(crd, 0, param->win->size->y);
	}
}
