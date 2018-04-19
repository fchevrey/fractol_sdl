/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:21:57 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/05 16:47:26 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iteration_max_up(t_param *param)
{
	if (param->fractal == JULIA)
		param->imax = param->imax + 20;
	else
		param->imax = param->imax + 50;
}

void	iteration_max_down(t_param *param)
{
	if (param->imax > 30)
	{
		if (param->fractal == JULIA)
			param->imax = param->imax - 20;
		else
			param->imax = param->imax - 50;
	}
}
