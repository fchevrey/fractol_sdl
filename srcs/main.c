/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:50:21 by fchevrey          #+#    #+#             */
/*   Updated: 2019/03/19 11:32:16 by fchevrey         ###   ########.fr       */
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
	if (!(param->win->texs = lst_tex_new((*param->win->size),
			param->win->ren, 0)))
		return (NULL);
	if (!(param->win->texs->next = lst_tex_new(pt_set(400, 240),
			param->win->ren, 1)))
		return (NULL);
	set_space(param->space);
	set_space_db(param->space_db);
	param->imax = 70;
	param->color = 0;
	param->lock = 0;
	return (param);
}

static void			print_controls()
{
	ft_putendl("c\t:\tchange color");
	ft_putendl("f\t:\tchange fractal");
	ft_putendl("*\t:\tprecision +");
	ft_putendl("/\t:\tprecision -");
	ft_putendl("+\t:\tzoom up");
	ft_putendl("-\t:\tzoom down");
	ft_putendl("arrows\t:\tmove");
	ft_putendl("mouse Wheel\t:\tzoomm at a precise point");
	ft_putendl("on JULIA :");
	ft_putendl("mouse move change the value of the fractal");
	ft_putendl("L\t:\tlock the mouse position");
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
	print_controls();
	ft_event((void*)param);
	return (0);
}
