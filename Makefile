# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 19:51:49 by dcyprien          #+#    #+#              #
#    Updated: 2022/01/20 15:28:51 by dcyprien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/get_next_line.c\
			./srcs/so_long.c\
			./srcs/ft_split.c\
			./srcs/ft_strlen.c\
			./srcs/ft_substr.c\
			./srcs/ft_calloc.c\
			./srcs/ft_strchr.c\
			./srcs/ft_bzero.c\
			./srcs/ft_strdup.c\
			./srcs/ft_memmove.c\
			./srcs/ft_memcpy.c\
			./srcs/ft_strjoin.c\
			./srcs/ft_strlcat.c\
			./srcs/ft_strlcpy.c\
			./srcs/map_parsing.c\
			./srcs/initialization.c\
			./srcs/launch.c\
			./srcs/put_images.c\
			./srcs/events.c\
			./srcs/move.c\
			./srcs/ft_cinset.c\
			./srcs/map_parsing_2.c\
			./srcs/ft_itoa.c

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

srcs/%.o: 	srcs/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_Linux -O3 -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -L./mlx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lz -o $(NAME)

all:		${NAME}

clean:		
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY = all clean fclean re

