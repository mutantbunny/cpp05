CC = c++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98
RM = rm -f

NAME = ex03

SRCS = AForm.cpp Bureaucrat.cpp Intern.cpp PresidentialPardonForm.cpp
SRCS += RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

INCS = AForm.hpp Bureaucrat.hpp Intern.hpp PresidentialPardonForm.hpp
INCS += RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

re: fclean all