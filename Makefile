# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 23:35:47 by vicmarti          #+#    #+#              #
#    Updated: 2021/06/20 21:04:28 by vicmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH := sources/

MAKEFILES += " -j $(shell sysctl -n hw.ncpu)"

NAME := fractol

SRCS :=

INCLUDES := includes
OBJS := objects

#CMN_SRC :=  $(addprefix $(SRC_DIR)/common, $(CHK_FILES))
#CHK_SRC :=  $(addprefix $(SRC_DIR)/checker, $(CHK_FILES))
#ALG_SRC :=  $(addprefix $(SRC_DIR)/algorithms, $(PSH_FILES))
#PHS_SRC :=  $(addprefix $(SRC_DIR)/push_swap, $(PSH_FILES))

CMN_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CMN_FILES)))
#CHK_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(CHK_FILES)))
PSH_OBJ := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(PSH_FILES)))

SRCS_BONUS :=
OBJ_BNS_FILES := $(patsubst %.c, %.o, $(SRC_BNS_FILES))

LIBS := -lft

SRC_BNS :=	$(addprefix $(SRC_DIR)/, $(SRC_BNS_FILES))
OBJ_BNS :=	$(addprefix $(OBJ_DIR)/, $(OBJ_BNS_FILES))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I$(INCLUDES) -g #-fsanitize=address

.PHONY: all re clean fclean norm run
all : $(NAME)

$(NAME) : $(CMN_OBJ) $(PSH_OBJ) $(LIBFT)
	@tput setaf 2
	@echo "Push_Swap:"
	@tput setaf 8
	$(CC) $(CFLAGS) $(LN_FLAGS) $^ -o $@
	@tput sgr0

$(LIBFT) :
	@make -C libft
	@ln -vfs libft/libft.h $(INC_DIR)/

$(OBJ_DIR)/%.o :%.c
	@mkdir -vp $(OBJ_DIR)
	@tput setaf 8
	$(CC) $(CFLAGS) $<  -c -o $@
	@tput sgr0

run : $(NAME)
	@./$(NAME)

norm :
	@norminette $(SRCS) $(SRCS_BONUS)

clean :
	@echo "Cleaning:"
	@tput setaf 3
	@rm -rfv $(OBJS)
	@tput sgr0

libclean :
	@make -C libft fclean
	@unlink $(INC_DIR)/libft.h

fclean : clean
	@rm -rv $(NAME)

re :
	@make fclean
	@make all
