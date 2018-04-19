/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:28:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 18:29:52 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void		*pth_mandelbrot(void *pth_param)
{
	t_pth_param		pth;
	t_ptfl			z;
	t_ptfl			c;
	t_point			i;

	pth = *(t_pth_param*)pth_param;
	c = ptfl_set(pth.lim.min.x, pth.lim.min.y);
	pth.space.position = ptfl_bc(pth.space.position, '/', pth.space.zoom);
	while (pth.crd.x < pth.x_max)
	{
		c.x = (pth.crd.x * pth.lim.incr.x) + pth.lim.min.x;
		c.y = (pth.crd.y * pth.lim.incr.y) + pth.lim.min.y;
		i = pt_set(0, pth.param->imax);
		z = ptfl_set(0, 0);
		i.x = get_i_value(i, z, c);
		color_with_i(i, pth.param, pth.img, pth.crd);
		pth.crd = pt_ypluseg(pth.crd, 0, pth.param->win->size->y);
	}
	return (NULL);
}
