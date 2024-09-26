# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 02:41:56 by yabenman          #+#    #+#              #
#    Updated: 2024/09/26 10:08:58 by yabenman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRCS = ft_printf.c ft_printf_utiles.c ft_strchr.c
	
OBJ_M = $(SRCS:.c=.o)


$(NAME): $(OBJ_M) 
	$(AR) $(NAME) $(OBJ_M)

%o:%c ft_printf.h
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJ_M)

fclean: clean
		$(RM) $(NAME)

re: fclean bonus all
