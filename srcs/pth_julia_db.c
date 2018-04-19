/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_julia_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:36:52 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 19:19:11 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			*pth_julia_db(void *pth_param)
{
	t_ptdb			z;
	t_ptdb			c;
	t_point			i;
	t_pth_param		pth;

	pth = *(t_pth_param*)pth_param;
	c = ptdb_set(pth.lim_db.min.x, pth.lim_db.min.y);
	i.x = 0;
	i.y = pth.param->imax;
	pth.space_db.position = ptdb_bc(pth.space_db.position, '/',
			pth.space_db.zoom);
	while (pth.crd.x < pth.x_max)
	{
		c.x = ((pth.param->mouse.x * 2.7) / 2560) - 2.1;
		c.y = ((pth.param->mouse.y * 2.4) / 1440) - 1.2;
		z.x = (pth.crd.x * pth.lim_db.incr.x) + pth.lim_db.min.x;
		z.y = (pth.crd.y * pth.lim_db.incr.y) + pth.lim_db.min.y;
		i.x = get_i_value_db(i, z, c);
		color_with_i(i, pth.param, pth.img, pth.crd);
		pth.crd = pt_ypluseg(pth.crd, 0, pth.param->win->size->y);
	}
	return (NULL);
}
