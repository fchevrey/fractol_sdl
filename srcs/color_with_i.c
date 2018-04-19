/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_with_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:15:57 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 16:12:27 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t		color_method_4(t_point i)
{
	uint32_t	color;
	int				v;

	v = i.x * 255;
	if (i.x < (i.y / 2))
		color = get_color(0, 0, (v * 2) / i.y, (v * 2) / i.y);
	else
		color = get_color(0, v / i.y, 0, (v / 2) / i.y);
	return (color);
}

static uint32_t		color_method_3(t_point i)
{
	uint32_t	color;
	int				v;

	v = i.x * 255;
	if (i.x < (i.y / 10))
		color = get_color(0, 0, 0, v / (i.y / 10));
	else if (i.x < (i.y / 3))
		color = get_color(0, v / i.y, v / (i.y / 3), 0);
	else if (i.x < (i.y / 1.5))
		color = get_color(0, v / (i.y / 1.5), v / (i.y / 2), 0);
	else
		color = get_color(0, v / i.y, 0, 0);
	return (color);
}

static uint32_t		color_method_2(t_point i)
{
	uint32_t	color;
	int				v;

	v = i.x * 255;
	if (i.x < (i.y / 5))
		color = get_color(0, (v * 5) / i.y, v * 2 / i.y, 0);
	else if (i.x < (i.y / 2))
		color = get_color(0, (v * 2) / i.y, v / i.y, 0);
	else
		color = get_color(0, v / i.y, v / i.y, 0);
	return (color);
}

static uint32_t		color_method_1(t_point i)
{
	uint32_t	color;
	int				v;

	v = i.x * 255;
	if (i.x < (i.y / 5))
		color = get_color(0, 0, (v * 3) / i.y, (v * 3) / i.y);
	else if (i.x < (i.y / 4))
		color = get_color(0, v / i.y, (v * 3) / i.y, (v * 3) / i.y);
	else if (i.x < (i.y / 3))
		color = get_color(0, v / i.y, (v * 3) / i.y, (v * 3) / i.y);
	else if (i.x < (i.y / 2))
		color = get_color(0, v / i.y, (v * 1.5) / i.y, (v * 2) / i.y);
	else if (i.x < i.y / 1.5)
		color = get_color(0, v / i.y, (v / 2) / i.y, (v * 1.25) / i.y);
	else
		color = get_color(0, v / i.y, 0, (v * 0.8) / i.y);
	return (color);
}

void					color_with_i(t_point i, t_param *param, t_image *img,
		t_point crd)
{
	uint32_t	color;

	color = 0;
	if (i.x == i.y && param->color != 4 && param->color != 1)
		color = get_color(255, 255, 255, 255);
	else if (i.x == i.y)
		color = get_color(0, 0, 0, 0);
	else if (param->color == 0)
		color = get_color(0, 0, (i.x * 255) / i.y, 0);
	else if (param->color == 1)
		color = color_method_1(i);
	else if (param->color == 2)
		color = color_method_3(i);
	else if (param->color == 3)
		color = color_method_2(i);
	else if (param->color == 4)
		color = color_method_4(i);
	else if (param->color == 5)
		color = get_color(0, 0, 0, (i.x * 255) / i.y);
	else if (param->color == 6)
		color = get_color(0, (i.x * 255) / i.y, 0, 0);
	pt_to_img(crd, img, color);
}
