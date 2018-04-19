/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_img_srch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:40:26 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:23:26 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmysdl.h"

t_image		*lst_img_srch(t_list *lst, int id)
{
	t_list		*item;
	t_image		*img;

	item = ft_lstsrch(lst, id);
	if (!item || !(item->content))
		return (NULL);
	img = (t_image*)item->content;
	return (img);
}
