# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/06/26 18:44:09 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h includes
vpath %.c src

MAKEFILES += " -j $(shell sysctl -n hw.ncpu)"

NAME := libftcomplex.a

SRCS :=
SRCS += ft_zset.c
SRCS += ft_zadd.c
SRCS += ft_zsub.c
#SRCS += ft_zmod.c
SRCS += ft_zmul.c
SRCS += ft_zdiv.c
SRCS += ft_zconj.c

OBJS := $(addprefix objects/, $(patsubst %.c, %.o, $(SRCS)))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -O3 -Iincludes

AR := ar
AFLAGS := -rc
.PHONY: all re clean fclean norm
all : $(NAME)

$(NAME) : $(OBJS)
	@tput setaf 2
	@echo "$(NAME):"
	@tput setaf 8
	$(AR) $(AFLAGS) $(NAME) $(OBJS)
	ranlib $(NAME)
	@tput sgr0

objects/%.o : %.c
	@mkdir -vp objects
	@tput setaf 8
	$(CC) $(CFLAGS) $(LIBS) $< -c -o $@
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
