/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:28:06 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/11 14:12:43 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	ft_exit(t_param **param)
{
	if (!param || !*param)
		exit(1);
	free_win(&(*param)->win);
	(*param)->win = NULL;
	free((*param)->space);
	free((*param)->space_db);
	free(*param);
	*param = NULL;
	exit(1);
}
