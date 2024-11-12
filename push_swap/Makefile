# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthant <hthant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 16:53:09 by hthant            #+#    #+#              #
#    Updated: 2024/10/20 22:05:50 by hthant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a
SRCS = main.c check_arguments.c index_check.c non_complex_sort.c push.c redix_sort.c reverse.c rotate.c swap.c t_stack.c utils.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	make -C ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean: clean
	make -C ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
