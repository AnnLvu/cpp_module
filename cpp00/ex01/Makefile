# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:36:01 by alvutina          #+#    #+#              #
#    Updated: 2024/10/24 12:36:02 by alvutina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
SRC = main.cpp PhoneBook.cpp Contact.cpp
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
