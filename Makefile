SRC =  main.cpp
NAME = test
COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(SRC)
	@$(COMPILER) $(FLAGS) $^ -o $@


t: re
	@clear
	@./progmar



clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
