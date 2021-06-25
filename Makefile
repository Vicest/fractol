# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/06/22 14:42:20 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH := src/:includes/

MAKEFILES += " -j $(shell sysctl -n hw.ncpu)"

NAME := libcomplex.a

SRCS :=
SRCS += ft_zset.c
SRCS += ft_zadd.c
SRCS += ft_zsub.c
SRCS += ft_zmod.c
SRCS += ft_zmul.c
SRCS += ft_zdiv.c
SRCS += ft_zconj.c

OBJS := $(addprefix objects/, $(patsubst %.c, %.o, $(SRCS)))

LIBS := -lm

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I. -L. -O3

.PHONY: all re clean fclean norm
all : $(NAME)

$(NAME) : $(OBJS)
	@tput setaf 2
	@echo "$(NAME):"
	@tput setaf 8
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@
	@tput sgr0

$(LIBFT) :
	@make -C libft
	@ln -vfs libft/libft.h $(INC_DIR)/

%.o :%.c
	@mkdir -vp objects
	@tput setaf 8
	$(CC) $(CFLAGS) $<  -c -o $@
	@tput sgr0

norm :
	@norminette $(SRCS)

clean :
	@echo "Cleaning:"
	@tput setaf 3
	@rm -rfv $(OBJS)
	@tput sgr0

fclean : clean
	@rm -rfv $(NAME)

re :
	@make fclean
	@make all
