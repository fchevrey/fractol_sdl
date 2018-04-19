/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:35:49 by fchevrey          #+#    #+#             */
/*   Updated: 2018/03/14 13:33:46 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_color(unsigned char alpha, unsigned char red,
		unsigned char green, unsigned char blue)
{
	unsigned int color;

	color = alpha;
	color = (color * 256) + red;
	color = (color * 256) + green;
	color = (color * 256) + blue;
	return (color);
}
