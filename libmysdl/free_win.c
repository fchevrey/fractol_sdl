/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:08:29 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 21:22:01 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmysdl.h"

void		free_win(t_win **win)
{
	if (!win || !*win)
		return ;
	free_all_img(&(*win)->imgs);
	(*win)->imgs = NULL;
	if ((*win)->ren != NULL)
		SDL_DestroyRenderer((*win)->ren);
	SDL_DestroyWindow((*win)->ptr);
	free(*win);
	*win = NULL;
}
