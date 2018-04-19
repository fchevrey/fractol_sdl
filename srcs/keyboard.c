/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:43:45 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 18:26:35 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int		do_event(int key, t_param *param)
{
	static t_funar_keyb		*tab_fct = NULL;
	static int				size_tab;
	int						i;

	if (key == 400)
		return (1);
	if (tab_fct == NULL)
		tab_fct = fill_funar_key_event(&size_tab);
	i = 0;
	if (key == SDLK_ESCAPE)
	{
		free(tab_fct);
		return (-1);
	}
	while (i < size_tab)
	{
		if (tab_fct[i].key == key)
		{
			tab_fct[i].f(param);
			return (1);
		}
		i++;
	}
	return (0);
}

int				keyboard(int key, void *param)
{
	t_win				*win;
	t_image				*img;
	//t_image				*ctrl_panel;
	int					ret;
	t_param				*par;

	par = (t_param*)param;
	win = par->win;
	img = lst_img_srch(par->win->imgs, 0);
	//ctrl_panel = lst_img_srch(par->win->imgs, 1);
	//if (!img || !ctrl_panel)
	//	ft_exit(&par);
	ret = 0;
	if ((ret = do_event(key, par)) == 1)
		fractal(img, par);
	if (ret == -1)
		ft_exit(&par);
	//put_ctrl_panel(ctrl_panel, win, par);
	if (key == SDLK_h)
		put_img_to_win(img, win->ren);
	return (0);
}
