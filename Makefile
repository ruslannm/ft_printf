# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <rgero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 15:46:56 by rgero             #+#    #+#              #
#    Updated: 2019/11/10 12:22:57 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = ./
SRC_NAME = main.c ft_printf.c

OBJ_PATH = ./
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC_PATH = ./libft/
INC = $(addprefix -I, $(INC_PATH))

LIB_PATH = libft/
LIB_NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB_PATH)$(LIB_NAME) $(OBJ_NAME)
	$(CC) -o $(NAME)  $(OBJ_NAME) -L $(LIB_PATH) -lft

%.o: %.c
	$(CC) $(CFLAGS) -I ${INC_PATH} -o $@  -c $<

$(LIB_PATH)$(LIB_NAME):
	make -C $(LIB_PATH)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean
fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIB_PATH)$(LIB_NAME)
	
re: fclean all
