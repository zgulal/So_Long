# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 13:07:57 by zgulal            #+#    #+#              #
#    Updated: 2023/03/21 15:32:11 by zgulal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c utils.c

OBJS 		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		=-Wall -Wextra -Werror

NAME		= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
clean: 
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
