# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthant <hthant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/09 16:49:26 by hthant            #+#    #+#              #
#    Updated: 2025/10/01 19:59:03 by hthant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface
SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp Character.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++ 
CFLAGS = #-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
