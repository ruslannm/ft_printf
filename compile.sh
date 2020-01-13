#! /bin/sh

NAME="ft_printf"

CC="gcc"
CFLAGS="-Wall -Wextra -Werror -g"

SRC_PATH="./"
SRC_NAME="ft_bigop.c ft_put_di_str.c"

INC_PATH="./libft/"


LIB_PATH="libft/"
LIB_NAME="libft.a"

$CC $CFLAGS $SRC_NAME -I $INC_PATH   -o $NAME  -L $LIB_PATH -lft
