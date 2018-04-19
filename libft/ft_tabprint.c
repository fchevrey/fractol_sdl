/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:40:01 by overetou          #+#    #+#             */
/*   Updated: 2017/12/03 20:12:30 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabprint(char **tab)
{
	int		i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}