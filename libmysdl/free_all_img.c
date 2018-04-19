/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:37:39 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/17 22:23:32 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

void	free_all_img(t_list **imgs)
{
	t_list		*lst;
	t_list		*lst_n;
	t_image		*img;

	if (!imgs || !(*imgs))
		return ;
	lst = *imgs;
	while (lst)
	{
		lst_n = lst->next;
		img = (t_image*)lst->content;
		free_img(&img);
		free(lst);
		lst = lst_n;
	}
}
