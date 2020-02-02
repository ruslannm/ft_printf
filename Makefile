# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <rgero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 15:46:56 by rgero             #+#    #+#              #
#    Updated: 2020/02/02 19:14:17 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
SRC_NAME = 	ft_check_format.c \
	ft_get_args.c \
	ft_get_arg_cspf.c \
	ft_get_arg_duox.c \
	ft_get_str_dif.c \
	ft_get_str_uoxp.c \
	ft_get_str_f_special_case.c \
	ft_parse_format.c \
	ft_parse_conversion.c \
	ft_parse_fields.c \
	ft_printf.c \
	ft_put_str_di.c \
	ft_put_str_f.c \
	ft_div_by2.c \
	ft_conv_bin_fracpart.c \
	ft_conv_bin_intpart.c \
	ft_conv_bin_dec.c \
	ft_mul_long.c \
	ft_roundup.c

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
	cp $(LIB_PATH)$(LIB_NAME) ./$(NAME)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
#	$(CC) -o $(NAME)  $(OBJ_NAME) -L $(LIB_PATH) -lft

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
