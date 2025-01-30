# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 16:42:33 by dgarcez-          #+#    #+#              #
#    Updated: 2025/01/30 19:17:50 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx_linux -lX11 -lXext -lbsd
SRCS =	so_main.c so_parsing.c so_map_parsing.c

OBJ_FILES =  $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT):
	make -C ./libft -s

$(MLX):
	make -C ./minilibx-linux -s
	
clean:
	make clean -C ./libft -s
	make clean -C ./minilibx-linux -s
	rm -f $(OBJ_FILES) $(LST_OBJ_FILES) $(OBJS_GET_NEXT_LINE)

fclean: clean
	make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all