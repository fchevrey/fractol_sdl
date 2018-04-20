/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:28:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:24:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** c et z sont des points et c.x représente la partie réel
** c.y = partie imaginaire
** le nb max d'itération definira la netteté de la fractale
** pour zoomer, il faudra augmenter la netteté
*/

void			mandelbrot(t_param *param, t_texture *img, t_limits lim,
		t_space space)
{
	t_ptfl			z;
	t_ptfl			c;
	t_point			i;
	t_point			crd;
	float			swap;

	c = ptfl_set(lim.min.x, lim.min.y);
	crd = pt_set(0, 0);
	space.position = ptfl_bc(space.position, '/', space.zoom);
	while (crd.x < param->win->size->x)
	{
		c.x = (crd.x * lim.incr.x) + lim.min.x;
		c.y = (crd.y * lim.incr.y) + lim.min.y;
		i = pt_set(0, param->imax);
		z = ptfl_set(0, 0);
		while (i.x < i.y && (((z.x * z.x) + (z.y * z.y)) < 4.0))
		{
			swap = z.x;
			z.x = (((z.x * z.x) - (z.y * z.y)) + c.x);
			z.y = ((2 * swap * z.y) + c.y);
			i.x = i.x + 1;
		}
		color_with_i(i, param, img, crd);
		crd = pt_ypluseg(crd, 0, param->win->size->y);
	}
}
