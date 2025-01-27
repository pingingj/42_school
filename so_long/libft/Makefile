# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarcez- <dgarcez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 15:54:43 by dgarcez-          #+#    #+#              #
#    Updated: 2025/01/14 16:48:40 by dgarcez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

FT_PRINTF_SRCS =  ft_printf/ft_printf.c ft_printf/ft_putstr.c ft_printf/ft_putnbr.c

GET_NEXT_LINE_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LST_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c

OBJ_FILES =  $(SRCS:.c=.o)

LST_OBJ_FILES = $(LST_FILES:.c=.o)

OBJS_FT_PRINTF = $(FT_PRINTF_SRCS:.c=.o)

OBJS_GET_NEXT_LINE = $(GET_NEXT_LINE_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ_FILES) $(OBJS_FT_PRINTF) $(OBJS_GET_NEXT_LINE)
	ar rcs $@ $^

bonus: $(NAME) $(LST_OBJ_FILES)
	@ar rcs $(NAME) $(LST_OBJ_FILES)
	
clean:
	make clean -C ./ft_printf -s
	rm -f $(OBJ_FILES) $(LST_OBJ_FILES)

fclean: clean
	make fclean -C ./ft_printf -s
	rm -f $(NAME)

re: fclean all