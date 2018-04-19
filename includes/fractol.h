/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:46:01 by fchevrey          #+#    #+#             */
/*   Updated: 2018/04/19 16:02:56 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libmysdl.h"
# include "mlx_keys_macos.h"
# define ZOOM_MAX_FL 30000
# define NB_THREAD 300

enum				e_fratal
{
	MANDELBROT, JULIA, BURNING_SHIP
};

typedef struct		s_limits
{
	t_ptfl		incr;
	t_ptfl		min;
	t_ptfl		max;
}					t_limits;

typedef struct		s_limits_db
{
	t_ptdb		incr;
	t_ptdb		min;
	t_ptdb		max;
}					t_limits_db;

typedef struct		s_space
{
	float		zoom;
	t_ptfl		position;
}					t_space;

typedef struct		s_space_db
{
	double		zoom;
	t_ptdb		position;
}					t_space_db;

typedef struct		s_param
{
	t_win			*win;
	t_space			*space;
	t_space_db		*space_db;
	t_point			mouse;
	int				imax;
	int				fractal;
	int				color;
	int				lock;
}					t_param;

typedef struct		s_pth_param
{
	t_param			*param;
	t_image			*img;
	t_space			space;
	t_space_db		space_db;
	t_limits		lim;
	t_limits_db		lim_db;
	t_point			crd;
	int				x_max;
}					t_pth_param;

typedef struct		s_funar_keyb
{
	int		key;
	void	(*f)(t_param*);
}					t_funar_keyb;

void				fractal(t_image *img, t_param *param);
void				set_space(t_space *space);
void				set_space_db(t_space_db *space);
t_limits			get_limits(t_point img_size, float zoom, t_ptfl pos);
t_limits_db			get_limits_db(t_point img_size, float zoom, t_ptdb pos);
void				mandelbrot(t_param *param, t_image *img, t_limits lim,
		t_space space);
void				julia(t_param *param, t_image *img, t_limits lim,
		t_space space);
void				burning_ship(t_param *param, t_image *img, t_limits lim,
		t_space space);
void				mandelbrot_db(t_param *param, t_image *img, t_limits_db lim,
		t_space_db space);
void				julia_db(t_param *param, t_image *img, t_limits_db lim,
		t_space_db space);
void				burning_ship_db(t_param *param, t_image *img,
		t_limits_db lim, t_space_db space);
int					get_i_value(t_point i, t_ptfl z, t_ptfl c);
int					get_i_value_db(t_point i, t_ptdb z, t_ptdb c);
void				*pth_mandelbrot(void *pth_param);
void				*pth_mandelbrot_db(void *pth_param);
void				*pth_julia(void *pth_param);
void				*pth_julia_db(void *pth_param);
void				*pth_burning_ship(void *pth_param);
void				*pth_burning_ship_db(void *pth_param);
unsigned int		get_color(unsigned char alpha, unsigned char red,
		unsigned char green, unsigned char blue);
int					keyboard(int key, void *param);
int					ft_mouse(int x, int y, void *param);
t_funar_keyb		*fill_funar_key_event(int *size);
void				color_with_i(t_point i, t_param *param, t_image *img,
		t_point crd);
void				move_up(t_param *param);
void				move_down(t_param *param);
void				move_left(t_param *param);
void				move_right(t_param *param);
void				zoom_up(t_param *param);
void				zoom_down(t_param *param);
void				change_color(t_param *param);
void				iteration_max_up(t_param *param);
void				iteration_max_down(t_param *param);
void				change_fractal(t_param *param);
void				lock(t_param *param);
void				ft_exit(t_param **param);
void				set_ctrl_panel(t_image *img, t_win *win);
void				put_ctrl_panel(t_image *img, t_win *win, t_param *param);
int					ft_mouse_wheel(int y, void *param);
void				ft_event(void *param);
#endif
