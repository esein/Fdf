# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 17:33:43 by gcadiou           #+#    #+#              #
#    Updated: 2017/10/29 17:39:59 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC = main.c   \
	  map.c    \
	  error.c  \

OBJ = $(SRC:.c=.o)

PATHLIB = ./Libft

LIB = $(PATHLIB)/libft.a

FLAG = -Wall -Werror -Wextra

all: compilib $(NAME)

$(NAME): $(LIB) $(SRC)
	gcc $(SRC) $(LIB) -I $(PATHLIB) -o $(NAME)
##	$(FLAG)

compilib:
	make -C $(PATHLIB)

.PHONY: compilib cleanlib clean fclean re

cleanlib:
	make clean -C $(PATHLIB)

clean: cleanlib
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
