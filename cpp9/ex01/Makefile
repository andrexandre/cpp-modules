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
NAME		:= RPN

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

VARS := "1 2 +"

run: re
	@./$(NAME) $(VARS)

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(VARS)

e: fclean

eval: $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
	./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"

.PHONY: all clean fclean re run e eval
