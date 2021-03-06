/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:28:06 by fchevrey          #+#    #+#             */
/*   Updated: 2019/03/19 11:08:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	ft_exit(t_param **param)
{
	ft_putstr("exit");
	if (!param || !*param)
		exit(1);
	free_win(&(*param)->win);
	(*param)->win = NULL;
	free((*param)->space);
	free((*param)->space_db);
	free(*param);
	*param = NULL;
	SDL_Quit();
	exit(1);
}
