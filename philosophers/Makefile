# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniel <daniel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 15:53:23 by dgarcez-          #+#    #+#              #
#    Updated: 2025/08/03 21:39:49 by daniel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SOURCES = philo.c creating.c utils.c

SRCS_DIR = srcs
SRCS =	$(addprefix $(SRCS_DIR)/, $(SOURCES))

OBJS_DIR = objs
OBJ_FILES =  $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo Compiling program
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo DONE!

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS)  -c $< -o $@
	
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

val: $(NAME)
	valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp -s ./minishell

#--trace-children=yes   

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all