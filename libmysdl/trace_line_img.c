/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:38:16 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:33:26 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

static void		huge_pente(t_point pt1, t_point pt2, t_image *img,
		uint32_t color)
{
	t_point		crd;
	float		pente;
	int			divideur;

	divideur = (pt2.x - pt1.x);
	if (divideur == 0)
		divideur = 1;
	pente = (float)(pt2.y - pt1.y) / divideur;
	if (pt1.y > pt2.y)
		pt_swap(&pt1, &pt2);
	crd = pt_set(pt1.x, pt1.y);
	pt_to_img(crd, img, color);
	while (++crd.y < pt2.y)
	{
		crd.x = pt1.x + (int)((crd.y - pt1.y) / pente);
		pt_to_img(crd, img, color);
	}
	pt_to_img(crd, img, color);
}

static void		low_pente(t_point pt1, t_point pt2, t_image *img,
		uint32_t color)
{
	t_point		crd;
	float		pente;
	int			divideur;

	divideur = (pt2.x - pt1.x);
	if (divideur == 0)
		divideur = 1;
	pente = (float)(pt2.y - pt1.y) / divideur;
	crd = pt_set(pt1.x, pt1.y);
	pt_to_img(crd, img, color);
	while (++crd.x < pt2.x)
	{
		crd.y = pt1.y + (int)(pente * (crd.x - pt1.x));
		pt_to_img(crd, img, color);
	}
	pt_to_img(crd, img, color);
}

void			trace_line_img(t_point pt1, t_point pt2, t_image *img,
		uint32_t color)
{
	float		pente;
	int			divideur;

	if (pt1.x > pt2.x)
		pt_swap(&pt1, &pt2);
	divideur = (pt2.x - pt1.x);
	if (divideur == 0)
		divideur = 1;
	pente = (float)(pt2.y - pt1.y) / divideur;
	if (pente > -1.5 && pente < 1.5)
		low_pente(pt1, pt2, img, color);
	else
		huge_pente(pt1, pt2, img, color);
}
