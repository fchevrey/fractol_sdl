/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:56:53 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/09 16:47:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** lim.min et lim.max sont fortement multiplié pour obtenir plus de précision
*/

t_limits		get_limits(t_point img_size, float zoom, t_ptfl pos)
{
	t_limits	lim;
	t_ptfl		lenght;
	float		x;
	float		y;

	x = img_size.x;
	y = img_size.y;
	lim.min.x = -4 / zoom;
	lim.max.x = 1 / zoom;
	lim.min.y = -2 / zoom;
	lim.max.y = 1 / zoom;
	lenght.x = lim.max.x - lim.min.x;
	lim.incr.x = (lenght.x) / x;
	lenght.y = lim.max.y - lim.min.y;
	lim.incr.y = (lenght.y) / y;
	lim.min.x = pos.x - (lenght.x / 2);
	lim.max.x = pos.x + (lenght.x / 2);
	lim.min.y = pos.y - (lenght.y / 2);
	lim.max.y = pos.y + (lenght.y / 2);
	return (lim);
}
