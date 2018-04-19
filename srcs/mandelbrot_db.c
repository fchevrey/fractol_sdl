/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:57:53 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 17:05:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** c et z sont des points et c.x représente la partie réel
** c.y = partie imaginaire
** le nb max d'itération definira la netteté de la fractale
** pour zoomer, il faudra augmenter la netteté
*/

void			mandelbrot_db(t_param *param, t_image *img, t_limits_db lim,
		t_space_db space)
{
	t_ptdb			z;
	t_ptdb			c;
	t_point			i;
	t_point			crd;
	double			swap;

	c = ptdb_set(lim.min.x, lim.min.y);
	crd = pt_set(0, 0);
	space.position = ptdb_bc(space.position, '/', space.zoom);
	while (crd.x < param->win->size.x)
	{
		c.x = (crd.x * lim.incr.x) + lim.min.x;
		c.y = (crd.y * lim.incr.y) + lim.min.y;
		i = pt_set(0, param->imax);
		z = ptdb_set(0, 0);
		while (i.x < i.y && (((z.x * z.x) + (z.y * z.y)) < 4.0))
		{
			swap = z.x;
			z.x = (((z.x * z.x) - (z.y * z.y)) + c.x);
			z.y = ((2 * swap * z.y) + c.y);
			i.x = i.x + 1;
		}
		color_with_i(i, param, img, crd);
		crd = pt_ypluseg(crd, 0, param->win->size.y);
	}
}
