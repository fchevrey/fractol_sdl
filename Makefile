# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/04/21 13:01:12 by fchevrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_BONUS = fractol_bonus

LIBFT = libft/libft.a

LIBPT = libpt/libpt.a

LIBVISU = libmysdl/libmysdl.a

USER = $(shell id -un)

SRC_PTHREAD = srcs/pth_fractal.c srcs/pth_mandelbrot.c srcs/pth_mandelbroth_db.c \
			srcs/pth_burning_ship.c srcs/pth_burning_ship_db.c \
			srcs/pth_julia.c srcs/pth_julia_db.c

SRC_VANILLA = srcs/mandelbrot.c srcs/burning_ship.c srcs/fractal.c \
			srcs/mandelbrot_db.c srcs/julia.c srcs/julia_db.c \
			srcs/burning_ship_db.c

SRC_C = srcs/main.c srcs/get_color.c srcs/keyboard.c srcs/ft_mouse_wheel.c \
		srcs/move.c srcs/zoom.c srcs/iteration_max.c srcs/get_limits.c \
		srcs/get_limits_db.c srcs/color_with_i.c srcs/lock.c \
		srcs/change_fractal.c srcs/ft_exit.c srcs/ft_mouse.c \
		srcs/set_space.c srcs/set_space_db.c srcs/fill_funar_key_event.c\
		srcs/get_i_value.c srcs/get_i_value_db.c srcs/ft_event.c \
		srcs/change_color.c
		#srcs/set_ctrl_panel.c srcs/put_ctrl_panel.c srcs/change_color.c \

SRC_O = $(SRC_C:.c=.o)

SRC_VANILLA_O = $(SRC_VANILLA:.c=.o)

SRC_PTHREAD_O = $(SRC_PTHREAD:.c=.o)

INCLUDE = -I /Users/$(USER)/.brew/Cellar/sdl2/2.0.8/include/SDL2 -I includes/
#INCLUDE = -I SDL2/SDL2-2.0.8/include/ -I includes/

#LIBS = -L SDL2/SDL2-2.0.8/build/.libs/ -lSDL2 
LIBS = -L /Users/$(USER)/.brew/Cellar/sdl2/2.0.8/lib/ -lSDL2 \
		-L libpt/ -lpt -L libft/ -lft -L libmysdl/ -lmysdl

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

CC = gcc

all: $(LIBVISU) $(NAME)

$(NAME): $(SRC_O) $(SRC_VANILLA_O)
	gcc -o $(NAME) $(SRC_O) $(SRC_VANILLA_O)  $(INCLUDE) $(INCLUDE_SDL) \
		$(LIBS)

bonus: $(LIBFT) $(LIBVISU) $(SRC_O) $(SRC_PTHREAD_O)
	gcc -o $(NAME_BONUS) $(SRC_O) $(SRC_PTHREAD_O) -D_REENTRANT \
		$(INCLUDE) $(INCLUDE_SDL) $(LIBS)

$(LIBFT):
	make -C libft/

$(LIBPT): $(LIBFT)
	make -C libpt/

$(LIBVISU): $(LIBPT) $(LIBSDL)
	make -C libmysdl/

SDL: 
	brew install sdl2
	brew link sdl2

clean:
	rm -f $(SRC_O) $(SRC_TEST_O) $(SRC_PTHREAD_O) $(SRC_VANILLA_O)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C  libft/ fclean
	make -C  libmysdl/ fclean
	make -C  libpt/ fclean

re: fclean all

.PHONY: all, clean, fclean, re, all, $(LIBVISU), $(LIBFT), $(LIBPT)
