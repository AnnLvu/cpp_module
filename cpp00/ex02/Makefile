# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:55:12 by alvutina          #+#    #+#              #
#    Updated: 2024/10/24 14:01:21 by alvutina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRCS = Account.cpp tests.cpp
OBJ 	=	$(SRCS:.cpp=.o)
CC = clang++

CFLAGS  = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re