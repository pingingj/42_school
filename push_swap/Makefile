# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:24:52 by dgarcez-          #+#    #+#              #
#    Updated: 2025/01/06 19:23:00 by dgarcez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	libft_func.c check_errors.c list_func.c stack_funcs.c \
		push_sort_utils.c push_swap_utils.c push_sort.c push_swap.c

OBJ_FILES =  $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT):
	make -C ./libft -s

clean:
	make clean -C ./libft -s
	rm -f $(OBJ_FILES) $(LST_OBJ_FILES)

fclean: clean
	make fclean -C ./libft -s
	rm -f $(NAME)

re: fclean all
