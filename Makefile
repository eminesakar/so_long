# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:26:15 by emsakar           #+#    #+#              #
#    Updated: 2023/10/09 18:01:35 by emsakar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/game.c src/map_constraction.c src/map_validation.c src/draw.c src/utils.c src/input.c src/path_finding.c
INC = inc
NAME = so_long
CFLAGS = -Wall -Werror -Wextra
FRAMEWORKS = -framework OpenGL -framework AppKit
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(SRC)
	@make -C mlx
	@gcc -g -o $(NAME) $(SRC) $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

clean:
	@rm -rf $(NAME)

fclean: clean
	@make -C mlx clean

re: fclean all

.PHONY: clean fclean re all
