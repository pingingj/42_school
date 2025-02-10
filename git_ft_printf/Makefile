# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 16:02:38 by dgarcez-          #+#    #+#              #
#    Updated: 2024/11/11 17:02:27 by dgarcez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putstr.c ft_putnbr.c

OBJ_FILES =  $(SRCS:.c=.o)

all: $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^
	
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	
re: fclean all