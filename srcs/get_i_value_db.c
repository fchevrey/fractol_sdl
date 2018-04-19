/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i_value_db.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:49:36 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 16:50:09 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_i_value_db(t_point i, t_ptdb z, t_ptdb c)
{
	double		swap;

	i.x = 0;
	while (i.x < i.y && (((z.x * z.x) + (z.y * z.y)) < 4.0))
	{
		swap = z.x;
		z.x = (((z.x * z.x) - (z.y * z.y)) + c.x);
		z.y = ((2 * swap * z.y) + c.y);
		i.x = i.x + 1;
	}
	return (i.x);
}
