/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:14:10 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/09 17:54:51 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_param *param)
{
	t_space		*space;
	t_space_db	*space_db;

	space = param->space;
	space_db = param->space_db;
	if (space_db->zoom < ZOOM_MAX_FL)
		space->position.y = space->position.y - (1.5 / space->zoom);
	space_db->position.y = space_db->position.y - (1.5 / space_db->zoom);
}

void	move_down(t_param *param)
{
	t_space		*space;
	t_space_db	*space_db;

	space = param->space;
	space_db = param->space_db;
	if (space_db->zoom < ZOOM_MAX_FL)
		space->position.y = space->position.y + (1.5 / space->zoom);
	space_db->position.y = space_db->position.y + (1.5 / space_db->zoom);
}

void	move_left(t_param *param)
{
	t_space		*space;
	t_space_db	*space_db;

	space = param->space;
	space_db = param->space_db;
	if (space_db->zoom < ZOOM_MAX_FL)
		space->position.x = space->position.x - (1.5 / space->zoom);
	space_db->position.x = space_db->position.x - (1.5 / space_db->zoom);
}

void	move_right(t_param *param)
{
	t_space		*space;
	t_space_db	*space_db;

	space = param->space;
	space_db = param->space_db;
	if (space_db->zoom < ZOOM_MAX_FL)
		space->position.x = space->position.x + (1.5 / space->zoom);
	space_db->position.x = space_db->position.x + (1.5 / space_db->zoom);
}
