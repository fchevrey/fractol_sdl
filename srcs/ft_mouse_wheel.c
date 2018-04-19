/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_wheel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:17:35 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 19:25:47 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_pos(int x, int y, t_param *param)
{
	t_limits_db		lim_db;
	t_limits		lim;
	t_point			size;

	size = pt_set(param->win->size->x, param->win->size->y);
	lim = get_limits(size, param->space->zoom, param->space->position);
	lim_db = get_limits_db(size, param->space_db->zoom,
			param->space_db->position);
	param->space_db->position.x = (x * lim_db.incr.x) + lim_db.min.x;
	param->space_db->position.y = (y * lim_db.incr.y) + lim_db.min.y;
	param->space->position.x = (x * lim.incr.x) + lim.min.x;
	param->space->position.y = (y * lim.incr.y) + lim.min.y;
}

int				ft_mouse_wheel(int y, void *param)
{
	t_param		*par;

	par = (t_param*)param;
	if (y > 0)
	{
		keyboard(SDLK_KP_PLUS, param);
		change_pos(par->mouse.x, par->mouse.y, par);
	}
	else
		keyboard(SDLK_KP_MINUS, param);
	return (0);
}
