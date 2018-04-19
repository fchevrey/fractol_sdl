/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctrl_panel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:11:24 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/06 15:14:57 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_ctrl_panel(t_image *img, t_win *win)
{
	unsigned int	color;

	color = mlx_get_color_value(win->mlx_ptr, 0xBB000000);
	fill_img_in_color(img, color);
}
