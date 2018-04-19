# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 17:05:18 by fchevrey          #+#    #+#              #
#    Updated: 2018/04/19 15:00:27 by fchevrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmysdl

SRC_C = get_color.c image_new.c free_img.c pt_to_img.c fill_img_in_color.c \
		lst_img_new.c free_all_img.c add_new_img.c lst_img_srch.c \
		trace_line_img.c put_img_to_win.c win_new.c free_win.c

SRC_O = $(SRC_C:.c=.o)

INCLUDE = -I ../includes/ -I /Users/fchevrey/.brew/Cellar/sdl2/2.0.8/include/

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

LIBS = -L ../libft/ -lft -L /Users/fchevrey/.brew/Cellar/sdl2/2.0.8/lib/ -lSDL2 -L ../libpt/ -lpt

CC = gcc

all: $(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	rm -f $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, all
