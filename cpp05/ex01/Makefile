NAME = ex01
SRCS = Bureaucrat.cpp main.cpp Form.cpp
OBJ = $(SRCS:.cpp=.o)
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
