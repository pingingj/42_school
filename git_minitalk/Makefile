# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 10:57:42 by root              #+#    #+#              #
#    Updated: 2025/02/26 18:25:59 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CNAME = client

LIBFT = ./incs/libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SOURCES =	server.c
CSOURCES =	client.c
	
SRCS_DIR = srcs
SRCS =	$(addprefix $(SRCS_DIR)/, $(SOURCES))

CSRCS_DIR = client_srcs
CSRCS =	$(addprefix $(CSRCS_DIR)/, $(CSOURCES))

OBJS_DIR = objs
COBJS_DIR = cobjs

OBJ_FILES =  $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
COBJ_FILES =  $(addprefix $(COBJS_DIR)/, $(CSOURCES:.c=.o))

all: $(NAME) $(CNAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(CNAME): $(COBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(COBJ_FILES) $(LIBFT) -o $(CNAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(COBJS_DIR)/%.o: $(CSRCS_DIR)/%.c | $(COBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./incs/libft -s
	
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(COBJS_DIR):
	@mkdir -p $(COBJS_DIR)

clean:
	make clean -C ./incs/libft -s
	@rm -rf $(OBJS_DIR)
	@rm -rf $(COBJS_DIR)

fclean: clean
	make fclean -C ./incs/libft -s
	rm -f $(NAME)
	rm -f $(CNAME)
re: fclean all