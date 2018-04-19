/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:43:20 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/05 16:39:48 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_fractal(t_param *param)
{
	param->fractal = param->fractal + 1;
	if (param->fractal > BURNING_SHIP)
		param->fractal = MANDELBROT;
	param->imax = 70;
	if (param->fractal == JULIA)
		param->imax = 35;
	set_space(param->space);
	set_space_db(param->space_db);
}
