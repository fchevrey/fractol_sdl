/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:14:55 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 16:01:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_event(void *param)
{
	SDL_Event	event;

	while (1)
	{
		SDL_Wait_Event(&event);
		if (event.type == KEY_DOWN)
			keyboard(event.key.keysym.sym, param);
		else if (event.type == SDL_MOUSEMOTION)
			ft_mouse(event.motion.x, event.motion.y, param);
		else if (event.type == KEY_MOUSEWHEEL)
			ft_mouse_wheel(event.wheel.y, param);
	}

}
