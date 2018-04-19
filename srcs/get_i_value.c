/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:49:16 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 16:49:19 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_i_value(t_point i, t_ptfl z, t_ptfl c)
{
	float		swap;

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
