END			:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
MAGENTA		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -g -std=c++98

OBJSDIR		:= objs
SRCS		:= $(wildcard *.cpp)
OBJS		:= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
NAME		:= PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "\n$(BLUE)$(NAME)$(END) $(GREEN)stuff compiled$(END) 💻\n"

$(OBJSDIR)/%.o: %.cpp
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJSDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\n$(BLUE)$(NAME)$(END) $(GREEN)stuff removed$(END) 🗑️\n"

re: fclean all

VARS := 3 5 9 7 4

run: re
	@./$(NAME) $(VARS)

test: $(NAME)
	@read -p "Enter the size of the array: " SIZE; \
	./$(NAME) `shuf -i 1-100000 -n $$SIZE | tr "\n" " "`

eval: $(NAME)
	./$(NAME) 3 5 9 7 4
	@echo
	./$(NAME) `shuf -i 1-100000 -n 5 | tr "\n" " "`
	@echo
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
	@echo
	./$(NAME) "-1" "2"

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(VARS)

e: fclean

.PHONY: all clean fclean re run e test eval
