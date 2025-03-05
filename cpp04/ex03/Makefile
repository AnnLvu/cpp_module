NAME = interface
SRCS = main.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp AMateria.cpp
OBJ = $(SRCS:.cpp=.o)
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
