# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 17:33:43 by gcadiou           #+#    #+#              #
#    Updated: 2017/10/30 00:36:03 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC = main.c   \
	  map.c    \
	  error.c  \
	  image_mlx.c

OBJ = $(SRC:.c=.o)

PATHLIB = ./Libft

PATHMLX = minilibx_macos

MLXFLAGS = -lmlx -framework OpenGL -framework Appkit

LIB = $(PATHLIB)/libft.a

FLAG = -Wall -Werror -Wextra

all: compilib $(NAME)

$(NAME): $(LIB) $(SRC)
	gcc $(SRC) $(LIB) $(MLXFLAGS) -I $(PATHLIB) -L $(PATHMLX) -o $(NAME)
##$(FLAG)

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
