# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/06/30 13:22:03 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c src/

MAKEFILES += " -j $(shell sysctl -n hw.ncpu)"

NAME := fractol

SRCS :=
SRCS += fractol.c
SRCS += initialize_fractal.c
SRCS += validate_args.c
SRCS += get_coords.c
#SRCS += validate_arguments.c
SRCS += colorize.c
SRCS += set_pixel.c
SRCS += print_fractal.c
SRCS += mandelbrot.c
SRCS += julia.c
#SRCS += newton.c

OBJS := $(addprefix objects/, $(patsubst %.c, %.o, $(SRCS)))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g #-O3 -g
LDFLAGS := -Llibmlx -Llibft -Lcomplex
LDLIBS := -lmlx -framework OpenGL -framework AppKit -lft -lftcomplex

.PHONY: all re clean fclean norm run
all : $(NAME)

$(NAME) : $(OBJS) libft/libft.a libmlx/libmlx.a complex/libftcomplex.a
	@tput setaf 2
	@echo "$(NAME):"
	@tput setaf 8
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@tput sgr0

complex/libftcomplex.a :
	@make -C complex

libft/libft.a :
	@make -C libft

libmlx/libmlx.a :
	@make -j $(shell sysctl -n hw.ncpu) -C libmlx

objects/%.o :%.c fractol.h libft/libft.h complex/includes/libftcomplex.h
	@mkdir -vp objects
	@tput setaf 8
	$(CC) $(CFLAGS) -I. -Ilibft -Icomplex/includes $<  -c -o $@
	@tput sgr0

norm :
	@norminette $(SRCS)

run : $(NAME)
	@./$(NAME) mandelbrot

clean :
	@echo "Cleaning:"
	@tput setaf 3
	@rm -rfv $(OBJS)
	@tput sgr0

fclean : clean
	@rm -rfv $(NAME)
	@make -C libft fclean
	@make -C libmlx clean
	@make -C complex fclean

re :
	@make fclean
	@make all
