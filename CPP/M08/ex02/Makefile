#  **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthant <hthant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 22:04:39 by hthant            #+#    #+#              #
#    Updated: 2025/09/09 01:33:49 by hthant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MuatatntStack

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

