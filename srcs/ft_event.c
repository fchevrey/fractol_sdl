/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:27:24 by fchevrey          #+#    #+#             */
/*   Updated: 2018/08/08 15:10:43 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	ft_event(void *param)
{
	SDL_Event	event;
	int			quit;
	t_param		*par;

	par = (t_param*)param;
	quit = 0;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			quit = 1;
		else if (event.type == SDL_KEYDOWN)
			keyboard(event.key.keysym.sym, param);
		else if (event.type == SDL_MOUSEMOTION)
			ft_mouse(event.motion.x, event.motion.y, param);
		else if (event.type == SDL_MOUSEWHEEL)
			ft_mouse_wheel(event.wheel.y, param);
	}
	ft_exit(&par);
}
