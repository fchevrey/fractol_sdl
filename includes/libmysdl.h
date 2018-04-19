/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmysdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:29:02 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/18 21:09:22 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYSDL_H
# define LIBMYSDL_H
# include "libpt.h"
# include "libft.h"
# include "SDL2/SDL.h"
# include <stdint.h>

typedef struct		s_image
{
	uint32_t		*tab_pxl;
	SDL_Texture		*tex;
	t_point			*size;
}					t_image;

typedef struct		s_win
{
	SDL_Window		*ptr;
	t_point			*size;
	t_list			*imgs;
	SDL_Renderer	*ren;
}					t_win;

uint32_t			get_color(uint8_t alpha, uint8_t red, uint8_t green,
		uint8_t blue);
t_win				*win_new(t_point size, char *title);
t_image				*image_new(t_point size, SDL_Renderer *ren);
t_image				*lst_img_srch(t_list *lst, int id);
t_list				*lst_img_new(t_point size, SDL_Renderer *ren, int id);
int					add_new_img(t_point size, SDL_Renderer *ren, t_list *src);
void				free_img(t_image **img);
void				free_win(t_win **win);
void				free_all_img(t_list **imgs);
void				pt_to_img(t_point pt, t_image *img, uint32_t color);
void				fill_rectangle(t_point left, t_point right, t_image *img,
		uint32_t color);
void			trace_line_img(t_point pt1, t_point pt2, t_image *img,
		uint32_t color);
void				fill_img_in_color(t_image *img, uint32_t color);
void				put_img_to_win(t_image *img, SDL_Renderer *ren);

#endif
