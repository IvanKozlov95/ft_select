# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 02:53:40 by ivankozlov        #+#    #+#              #
#    Updated: 2019/06/24 23:34:22 by ivankozlov       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

# compiler
CC = gcc

ifndef C_ENV
	export C_ENV=PROD
endif
ifeq (${C_ENV}, DEV)
	FLAGS = -g
else ifeq (${C_ENV}, PROD)
	FLAGS = -Wall -Wextra -Werror
endif

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# files
SRC := $(wildcard $(SRC_DIR)*.c)
OBJ := $(SRC:$(SRC_DIR)%=%)
OBJ := $(patsubst %, $(OBJ_DIR)%, $(OBJ:.c=.o))

# libft
LIBFT = $(LIBFT_DIR)libft.a

# libs
LIB = -L $(LIBFT_DIR) -lft -ltermcap

# includes
INCLUDES = -I $(LIBFT_DIR)$(INC_DIR) -I $(INC_DIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@echo $(OBJ)
	@echo $(SRC)

	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LIB) -o $(NAME) $(OBJ)
	@echo "[INFO] $(NAME) executable created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d "./$(OBJ_DIR)" ]; then\
		/bin/rm -rf $(OBJ_DIR);\
		/bin/echo "[INFO] Objects removed.";\
	fi;

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if test -e $(NAME); then\
		/bin/rm $(NAME);\
		/bin/echo "[INFO] $(NAME) executable deleted";\
	fi;

re: fclean all

.PHONY: all $(NAME) clean fclean re