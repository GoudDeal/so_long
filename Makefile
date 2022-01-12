# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 19:51:49 by dcyprien          #+#    #+#              #
#    Updated: 2022/01/12 00:39:58 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/get_next_line.c\
			./srcs/get_next_line_utils.c\
			./srcs/so_long.c

NAME	=	so_long

CC		=	gcc 

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

srcs/%.o: 	srcs/%.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_Linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

all:		${NAME}

clean:		
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY = all clean fclean re

