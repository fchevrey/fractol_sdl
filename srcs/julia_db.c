/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:17:50 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 18:30:37 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** c et z sont des points et c.x représente la partie réel
** c.y = partie imaginaire
** le nb max d'itération definira la netteté de la fractale
** pour zoomer, il faudra augmenter la netteté
*/

void			julia_db(t_param *param, t_image *img, t_limits_db lim,
		t_space_db space)
{
	t_ptdb			z;
	t_ptdb			c;
	t_point			i;
	t_point			crd;

	c = ptdb_set(lim.min.x, lim.min.y);
	i.x = 0;
	i.y = param->imax;
	space.position = ptdb_bc(space.position, '/', space.zoom);
	while (crd.x < param->win->size->x)
	{
		c.x = ((param->mouse.x * 2.7) / 2560) - 2.1;
		c.y = ((param->mouse.y * 2.4) / 1440) - 1.2;
		z.x = (crd.x * lim.incr.x) + lim.min.x;
		z.y = (crd.y * lim.incr.y) + lim.min.y;
		i.x = get_i_value_db(i, z, c);
		color_with_i(i, param, img, crd);
		crd = pt_ypluseg(crd, 0, param->win->size->y);
	}
}
