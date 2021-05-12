# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 09:52:34 by anclarma          #+#    #+#              #
#    Updated: 2021/05/09 12:18:06 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= push_swap
NAME2		= checker
SRCS1		= 
SRCS2		= 
OBJS1		= $(SRCS1:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) $< -o $(<:.c=.o)

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
