# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoulaim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 18:14:43 by msoulaim          #+#    #+#              #
#    Updated: 2020/02/14 18:15:34 by msoulaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = init_fdf.c main.c checker.c draw_fdf.c event.c free.c get_coord.c gnl/get_next_line.c ft_htoi.c

OBJ = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

MLX = -I minilibx_macos -L minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRCS)
	norminette fdf.h
