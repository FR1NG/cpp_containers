SRC =  main.cpp
NAME = progmar
OBJ=$(SRC:.cpp=.o)
COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(OBJ)
	$(COMPILER) $(FLAGS) $^ -o $@

%.o:%.cpp %.hpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
