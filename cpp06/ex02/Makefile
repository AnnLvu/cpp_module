NAME = ex02
SRCS = main.cpp Functions.cpp Base.cpp
OBJ = $(SRCS:.cpp=.o)
CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp A.hpp B.hpp C.hpp Base.hpp Functions.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
