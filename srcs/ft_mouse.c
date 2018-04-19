/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:15:31 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 18:11:41 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int x, int y, void *param)
{
	t_param		*par;

	par = param;
	if (par->lock == 0)
	{
		par->mouse.x = x;
		par->mouse.y = y;
		if (par->fractal == JULIA)
			keyboard(400, param);
	}
	return (0);
}
