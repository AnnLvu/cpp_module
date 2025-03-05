NAME = zombie

SRCS = main.cpp randomChump.cpp Zombie.cpp newZombie.cpp
OBJ = $(SRCS:.cpp=.o)
CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

