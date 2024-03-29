SRC =  main.cpp
NAME = test
COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(SRC)
	@$(COMPILER) $(FLAGS) $^ -o $@


t: clear_propt re
	@clear
	@./${NAME}

clear_propt:
	@clear
debug: fclean cdebug
	@./debug

cdebug: $(SRC) 
	@$(COMPILER) $(FLAGS) -fsanitize=address $^ -o debug

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf debug

re: fclean all
