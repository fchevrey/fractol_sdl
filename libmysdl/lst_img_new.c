/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_img_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:27:27 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 18:00:33 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

t_list		*lst_img_new(t_point size, SDL_Renderer *ren, int id)
{
	t_image		*img;
	t_list		*lst;

	img = image_new(size, ren);
	lst = ft_lstnew(img, id);
	return (lst);
}
