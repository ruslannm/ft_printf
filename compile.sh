#! /bin/sh

NAME="ft_printf"

CC="gcc"
CFLAGS="-Wall -Wextra -Werror -g"

SRC_PATH="./"
SRC_NAME="main.c"

INC_PATH="./"


LIB_PATH="/"
LIB_NAME="libftprintf.a"

$CC $CFLAGS $SRC_NAME -I $INC_PATH   -o $NAME  -L "./libft/" -lft  
