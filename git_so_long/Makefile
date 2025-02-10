# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 16:42:33 by dgarcez-          #+#    #+#              #
#    Updated: 2025/02/10 17:55:23 by dgarcez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX = 	./incs/minilibx-linux/libmlx.a
LIBFT = ./incs/libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx_linux -Imlx_linux -lX11 -lXext

SOURCES =	so_main.c so_parsing.c so_map_parsing.c so_utils.c so_clean.c so_events.c so_map_making.c
SRCS_DIR = srcs
SRCS =	$(addprefix $(SRCS_DIR)/, $(SOURCES))

OBJS_DIR = objs
OBJ_FILES =  $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./incs/libft -s

$(MLX):
	make -C ./incs/minilibx-linux -s
	
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

map1: all
	./$(NAME) maps/map1.ber

map2: all
	./$(NAME) maps/map2.ber


clean:
	make clean -C ./incs/libft -s

	make clean -C ./incs/minilibx-linux -s
	@rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C ./incs/libft -s

	rm -f $(NAME)

re: fclean all