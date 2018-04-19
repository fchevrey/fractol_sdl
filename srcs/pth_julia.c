/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:04:47 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 19:19:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			*pth_julia(void *pth_param)
{
	t_ptfl			z;
	t_ptfl			c;
	t_point			i;
	t_pth_param		pth;

	pth = *(t_pth_param*)pth_param;
	c = ptfl_set(pth.lim.min.x, pth.lim.min.y);
	i.x = 0;
	i.y = pth.param->imax;
	pth.space.position = ptfl_bc(pth.space.position, '/', pth.space.zoom);
	while (pth.crd.x < pth.x_max)
	{
		c.x = ((pth.param->mouse.x * 2.7) / 2560) - 2.1;
		c.y = ((pth.param->mouse.y * 2.4) / 1440) - 1.2;
		z.x = (pth.crd.x * pth.lim.incr.x) + pth.lim.min.x;
		z.y = (pth.crd.y * pth.lim.incr.y) + pth.lim.min.y;
		i.x = get_i_value(i, z, c);
		color_with_i(i, pth.param, pth.img, pth.crd);
		pth.crd = pt_ypluseg(pth.crd, 0, pth.param->win->size->y);
	}
	return (NULL);
}
