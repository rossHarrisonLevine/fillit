#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 15:21:19 by rlevine           #+#    #+#              #
#    Updated: 2017/08/01 21:10:45 by rlevine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = fillit.h

LIB = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra
.PHONY : clean

SRC =	validate.c errors.c main.c makemap.c support.c letterize.c \
solver1.c solver2.c solver3.c

OBJ = *.o

all: $(NAME)

$(NAME):
	make -C $(LIB)
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRC)
	$(CC) $(CFLAGS) -I$(HEADER) -L $(LIB) -lft $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB) clean

fclean:	clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all
