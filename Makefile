# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:07:16 by anclarma          #+#    #+#              #
#    Updated: 2021/05/14 23:13:51 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= push_swap
NAME2		= checker
SRCS1		= swap.c			\
			  push.c			\
			  rotate.c			\
			  rrotate.c			\
			  pile.c			\
			  push_swap.c		\
			  parse.c			\
			  solve.c			\
			  ft_is.c			\
			  ft_atoi.c			\
			  ft_secure_atoi.c
SRCS2		= checker.c			\
			  swap.c			\
			  push.c			\
			  rotate.c			\
			  rrotate.c			\
			  parse.c			\
			  solve.c			\
			  pile.c			\
			  ft_is.c			\
			  ft_atoi.c			\
			  ft_secure_atoi.c	\
			  get_next_line.c	\
			  ft_strdup.c		\
			  ft_strjoin.c		\
			  ft_strlen.c
OBJS1		= $(SRCS1:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME1)

$(NAME1):	$(OBJS1)
			$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2):	$(OBJS2)
			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

bonus:		$(NAME1) $(NAME2)

clean:
			rm -f $(OBJS1) $(OBJS2)

fclean:		clean
			rm -f $(NAME1) $(NAME2)

re:			fclean all

.PHONY:		all bonus clean fclean re
