/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ctrl_panel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:16:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/10 11:15:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		string_put(t_point *pt, t_win *win, unsigned int color,
		char *str)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, pt->x + 5, pt->y, color, str);
	pt->y = pt->y + 20;
}

static void		string_put_free(t_point *pt, t_win *win, unsigned int color,
		char **str)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, pt->x + 5, pt->y, color, *str);
	ft_strdel(str);
	pt->y = pt->y + 20;
}

static char		*join_int(int nb, char *str)
{
	char	*dst;
	char	*str_nb;

	str_nb = ft_itoa(nb);
	dst = ft_strjoin(str, str_nb);
	ft_strdel(&str_nb);
	return (dst);
}

void			put_ctrl_panel(t_image *img, t_win *win, t_param *param)
{
	t_point			pt;
	unsigned int	color;
	char			*str;

	pt = pt_set(2200, 0);
	color = mlx_get_color_value(win->mlx_ptr, 0xFFFFFF);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->ptr, pt.x, pt.y);
	string_put(&pt, win, color, "f          : change fractal");
	string_put(&pt, win, color, "+ and -    : zoom");
	string_put(&pt, win, color, "* and /    : change precision");
	string_put(&pt, win, color, "arrow keys : move");
	string_put(&pt, win, color, "c          : change color");
	string_put(&pt, win, color, "ESC        : quit");
	string_put(&pt, win, color, "h          : hide controls");
	string_put(&pt, win, color, "l          : lock julia value");
	pt.y = pt.y + 20;
	color = mlx_get_color_value(win->mlx_ptr, 0x3C5CD0);
	str = join_int((int)param->space_db->zoom, "actual zoom = x");
	string_put_free(&pt, win, color, &str);
	str = join_int((int)param->imax, "precision   = ");
	string_put_free(&pt, win, color, &str);
	if (param->lock == 1)
		string_put(&pt, win, color, "lock        = ON");
	else
		string_put(&pt, win, color, "lock        = OFF");
}
