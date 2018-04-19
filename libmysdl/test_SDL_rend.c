/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:03:46 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 19:04:31 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"
#include "../includes/libmysdl.h"

//la lib se trouve dans /Users/fchevrey/.brew/Cellar/sdl2/2.0.8/lib/

void	put_img_to_win2(t_image *img, SDL_Renderer *ren)
{
	SDL_Rect		rect = {0,0,50,50};

	SDL_UpdateTexture(img->tex, NULL, img->tab_pxl, img->size->x * sizeof(uint32_t));
	SDL_RenderCopy(ren, img->tex, NULL, &rect);
	SDL_RenderPresent(ren);
}

/*t_image		*black(SDL_Renderer *ren, t_point size)
{
	uint32_t		color;
	t_point			pt;
	t_image			*img;

	img = image_new(size, ren);
	if (!img)
		return (NULL);
	pt.y = 0;
	while (pt.y < size.y)
	{
		pt.x = 0;
		while (pt.x < size.x)
		{
			color = get_color(255, 255, 255, 255);
			pt_to_img(pt, img, color);
			pt.x = pt.x + 1;
		}
		pt.y = pt.y + 1;
	}
	return (img);
}*/

t_image		*dessin(SDL_Renderer *ren, t_point size) 
{
	uint32_t		color;
	uint8_t			r,g,b;
	t_point			pt;
	t_image			*img;

	img = image_new(size, ren);
	if (!img)
		return (NULL);
	pt.y = 0;
	while (pt.y < size.y)
	{
		pt.x = 0;
		while (pt.x < size.x)
		{
			r = 255 * pt.y / size.y;
			g = 255 * pt.x / size.x;
			b = 255 * (pt.x + pt.y) / (size.x + size.y);
			color = get_color(255, r, g, b);
			pt_to_img(pt, img, color);
			pt.x = pt.x + 1;
		}
		pt.y = pt.y + 1;
	}
	return (img);
}

t_image		*dessin2(SDL_Renderer *ren, t_point size) 
{
	uint32_t		color;
	uint8_t			r,g,b;
	t_point			pt;
	t_image			*img;

	img = image_new(size, ren);
	if (!img)
		return (NULL);
	pt.y = 0;
	ft_putcrd(size);
	while (pt.y < size.y)
	{
		pt.x = 0;
		while (pt.x < size.x)
		{
			r = 255 * pt.y / size.y;
			g = 255 * pt.x / size.x;
			b = 0;//255 * (pt.x + pt.y) / (size.x + size.y);
			color = get_color(255, r, g, b);
			pt_to_img(pt, img, color);
			pt.x = pt.x + 1;
		}
		pt.y = pt.y + 1;
	}
	return (img);
}

int		main(void)
{
	SDL_Window		*fen;
	SDL_Renderer	*ren;
	t_point			size;
	t_point			size2;
	t_image			*img;
	t_image			*img2;
	t_image			*fond;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("BUG\n");
		SDL_Quit();
		return (-1);
	}
	size.x = 800;
	size.y = 600;
	size2 = pt_set(50, 50);
	fen = NULL;
	//fen = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN_DESKTOP);
	//fen = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_FULLSCREEN_DESKTOP);
	fen = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.x, size.y, SDL_WINDOW_SHOWN | SDL_WINDOW_MINIMIZED);
	SDL_RestoreWindow(fen);
	if (fen != NULL)
	{
		//SDL_SetWindowFullscreen(fen, 0);
		ren = SDL_CreateRenderer(fen, 0, 0);
		img2 = dessin2(ren, size2);
		img = dessin(ren, size);
		fond = image_new(size, ren);
		fill_img_in_color(fond, get_color(255,255,0,0));
		put_img_to_win(img, ren);
		//SDL_RaiseWindow(fen);
		//SDL_MinimizeWindow(fen);
		SDL_Delay(3000);
		//SDL_MaximizeWindow(fen);
		SDL_RenderClear(ren);
		SDL_RenderPresent(ren);
		//SDL_SetWindowFullscreen(fen, SDL_WINDOW_FULLSCREEN);
		SDL_Delay(1000);
		put_img_to_win2(img2, ren);
		SDL_Delay(1000);
		SDL_RenderPresent(ren);
		SDL_Delay(1000);
		put_img_to_win(fond, ren);
		SDL_Delay(1000);
		//SDL_UpdateTexture(img2->tex, NULL, fond->tab_pxl, fond->size->x * sizeof(uint32_t));
		put_img_to_win2(img2, ren);
		SDL_Delay(3000);
		free_img(&img);
		free_img(&img2);
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(fen);
	}
	SDL_Quit();
	return (0);
}
