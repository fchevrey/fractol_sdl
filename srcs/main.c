/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:50:21 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 18:23:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int			ft_error(void)
{
	ft_putstr("usage ./fractol [1-3]\n");
	ft_putstr("1 = Mandelbrot\n");
	ft_putstr("2 = Julia\n");
	ft_putstr("3 = Burning ship\n");
	return (0);
}

static t_param		*set_param(void)
{
	t_param		*param;

	if (!(param = (t_param*)malloc(sizeof(t_param))))
		return (NULL);
	if (!(param->space = (t_space*)malloc(sizeof(t_space))))
		return (NULL);
	if (!(param->space_db = (t_space_db*)malloc(sizeof(t_space_db))))
		return (NULL);
	if (!(param->win = win_new(pt_set(2550, 1440), "fractol")))
		return (NULL);
	if (!(param->win->ren = SDL_CreateRenderer(param->win->ptr, 0, 0)))
		return (NULL);
	if (!(param->win->imgs = lst_img_new((*param->win->size),
			param->win->ren, 0)))
		return (NULL);
	//if (!(param->win->imgs->next = lst_img_new(pt_set(400, 240),
	//		param->win->ren, 1)))
	//	return (NULL);
	set_space(param->space);
	set_space_db(param->space_db);
	param->imax = 70;
	param->color = 0;
	param->lock = 0;
	return (param);
}

int					main(int ac, char **av)
{
	t_param		*param;
	int			input;

	if (ac != 2)
		return (ft_error());
	input = ft_atoi(av[1]);
	if (input < 1 || input > 3)
		return (ft_error());
	if (!(param = set_param()))
		return (0);
	param->fractal = input - 1;
	param->mouse = pt_set(500, 500);
	if (param->fractal == JULIA)
		param->imax = 35;
	keyboard(400, (void*)param);
	ft_event((void*)param);
	return (0);
}
