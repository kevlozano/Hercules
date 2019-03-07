# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/23 12:24:37 by mchi              #+#    #+#              #
#    Updated: 2019/02/25 11:32:35 by mchi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=src/check_line.c src/clean.c src/fillit.c src/fillout.c\
libft/ft_memset.c libft/ft_strlen.c libft/ft_strnew.c libft/ft_strsplit.c \
src/isvalid.c src/lstpush.c src/main.c src/readfile.c src/tetrimino_shift.c

OBJ=check_line.o clean.o fillit.o fillout.o ft_memset.o ft_strlen.o \
ft_strnew.o ft_strsplit.o isvalid.o lstpush.o main.o readfile.o tetrimino_shift.o

INC=-Ilibft -Isrc

FLAG=-Werror -Wall -Wextra -c $(INC)

NAME=fillit

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
