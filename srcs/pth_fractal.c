/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:04:04 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/20 15:07:02 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

static void			pth_fractal(t_param *param, t_texture *img, t_limits lim,
		void *(algo)(void*))
{
	t_pth_param		pth[NB_THREAD];
	int				screen;
	pthread_t		thread[NB_THREAD];
	int				i;
	t_limits_db		lim_db;

	screen = param->win->size->x / NB_THREAD;
	i = -1;
	lim_db = get_limits_db((*param->win->size), param->space_db->zoom,
				param->space_db->position);
	while (++i < NB_THREAD)
	{
		pth[i].param = param;
		pth[i].lim = lim;
		pth[i].lim_db = lim_db;
		pth[i].img = img;
		pth[i].space = *param->space;
		pth[i].space_db = *param->space_db;
		pth[i].crd = pt_set(screen * i, 0);
		pth[i].x_max = screen * (i + 1);
		pthread_create(&thread[i], NULL, algo, (void*)&pth[i]);
	}
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(thread[i], NULL);
}

void				fractal(t_texture *img, t_param *param)
{
	t_limits		lim;
	void			*(*tab[6])(void*);

	if (!param || !img || param->fractal > BURNING_SHIP)
		return ;
	tab[MANDELBROT] = &pth_mandelbrot;
	tab[JULIA] = &pth_julia;
	tab[BURNING_SHIP] = &pth_burning_ship;
	tab[3 + MANDELBROT] = &pth_mandelbrot_db;
	tab[3 + JULIA] = &pth_julia_db;
	tab[3 + BURNING_SHIP] = &pth_burning_ship_db;
	lim = get_limits((*param->win->size), param->space->zoom,
			param->space->position);
	if (param->space_db->zoom < ZOOM_MAX_FL)
		pth_fractal(param, img, lim, tab[param->fractal]);
	else if (param->space_db->zoom >= ZOOM_MAX_FL)
		pth_fractal(param, img, lim, tab[3 + param->fractal]);
	put_img_to_win(img, param->win->ren);
}
