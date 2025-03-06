# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 10:57:42 by root              #+#    #+#              #
#    Updated: 2025/03/06 15:37:20 by dgarcez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CNAME = client

LIBFT = ./incs/libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SERVER_SOURCES = mini_server.c mini_utils.c
CLIENT_SOURCES = mini_client.c mini_utils.c

SRCS_DIR = srcs
OBJ_DIR = objs

SERVER_OBJ = $(addprefix $(OBJ_DIR)/, $(SERVER_SOURCES:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJ_DIR)/, $(CLIENT_SOURCES:.c=.o))

all: $(NAME) $(CNAME)

$(NAME): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME)
	
$(CNAME): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CNAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C ./incs/libft -s

clean:
	make clean -C ./incs/libft -s
	@rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./incs/libft -s
	rm -f $(NAME) $(CNAME)

re: fclean all