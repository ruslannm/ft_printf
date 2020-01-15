# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <rgero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 15:46:56 by rgero             #+#    #+#              #
#    Updated: 2020/01/15 14:48:19 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = ./
SRC_NAME = main.c ft_printf.c ft_read_format.c ft_parse_fields.c \
	ft_parse_conversion.c ft_check_format.c \
	ft_put_di_str.c ft_put_uoxX_str.c ft_read_args.c ft_get_arg_d.c \
	ft_printf_len.c ft_put_csp_str.c \
	ft_get_arg_f.c ft_put_f_str.c ft_bigop.c

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
