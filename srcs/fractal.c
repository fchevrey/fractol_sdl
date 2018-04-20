/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:56:30 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 14:40:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fractal(t_texture *img, t_param *param)
{
	t_limits		lim;
	t_limits_db		lim_db;
	void			(*tab[3])(t_param*, t_texture*, t_limits, t_space);
	void			(*tab_db[3])(t_param*, t_texture*, t_limits_db, t_space_db);

	if (!param || !img || param->fractal > BURNING_SHIP)
		return ;
	tab[MANDELBROT] = &mandelbrot;
	tab[JULIA] = &julia;
	tab[BURNING_SHIP] = &burning_ship;
	tab_db[MANDELBROT] = &mandelbrot_db;
	tab_db[JULIA] = &julia_db;
	tab_db[BURNING_SHIP] = &burning_ship_db;
	if (param->space_db->zoom < ZOOM_MAX_FL)
		lim = get_limits((*param->win->size), param->space->zoom,
				param->space->position);
	else if (param->space_db->zoom >= ZOOM_MAX_FL)
		lim_db = get_limits_db((*param->win->size), param->space_db->zoom,
				param->space_db->position);
	if (param->space_db->zoom < ZOOM_MAX_FL)
		tab[param->fractal](param, img, lim, (*param->space));
	else if (param->space_db->zoom >= ZOOM_MAX_FL)
		tab_db[param->fractal](param, img, lim_db, (*param->space_db));
	put_tex_to_win(img, param->win->ren);
}
