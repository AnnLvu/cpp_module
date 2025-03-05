# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 11:13:55 by alvutina          #+#    #+#              #
#    Updated: 2024/10/24 11:46:31 by alvutina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
