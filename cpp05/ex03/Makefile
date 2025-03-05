NAME = ex03
SRCS = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ = $(SRCS:.cpp=.o)
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
