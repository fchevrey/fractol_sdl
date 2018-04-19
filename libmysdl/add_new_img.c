/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:50:03 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 18:01:04 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

int		add_new_img(t_point size, SDL_Renderer *ren, t_list *src)
{
	t_image		*img;
	t_list		*lst;
	int			id;

	if (!src)
		return (-1);
	if (!(img = image_new(size, ren)))
		return (-1);
	lst = src;
	id = -1;
	while (lst->next)
	{
		if (lst->id >= id)
			id = lst->id + 1;
		lst = lst->next;
	}
	if (!(lst->next = ft_lstnew(img, id)))
		return (-1);
	return (id);
}
