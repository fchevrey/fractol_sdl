/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:39:30 by fchevrey          #+#    #+#             */
/*   Updated: 2018/01/09 12:35:29 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(char ***tab)
{
	size_t		i;

	i = 0;
	if (!(*tab))
		return ;
	while (tab[0][i])
	{
		ft_strdel(&tab[0][i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
