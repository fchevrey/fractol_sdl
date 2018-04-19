/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:25:12 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/09 19:09:58 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_up(t_param *param)
{
	if (param->space->zoom < 10000000000)
	{
		param->space->zoom = param->space->zoom * 2;
		param->space_db->zoom = param->space_db->zoom * 2;
	}
}

void	zoom_down(t_param *param)
{
	if (param->space->zoom > 1)
	{
		param->space->zoom = param->space->zoom / 2;
		param->space_db->zoom = param->space_db->zoom / 2;
	}
}
