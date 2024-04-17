END			:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
MAGENTA		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

OBJSDIR		:= objs
SRCS		:= $(wildcard *.cpp)
OBJS		:= $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
NAME		:= main

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

VARS := 

run: re
	@./$(NAME) $(VARS)

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(VARS)

test:
	@clang++ -W -Wall -Werror *.cpp
	@./a.out | cat -e > out
	@echo "* shoots an ice bolt at bob *$$" > in
	@echo "* heals bob's wounds *$$" >> in
	@echo What you should show:
	@cat in
	@echo
	@echo What you actually show:
	@cat out
	@echo
	@diff -q out in >/dev/null && echo "OK" || echo "KO"
	@rm -f a.out out in

output:
	clang++ -W -Wall -Werror *.cpp
	./a.out | cat -e

e: fclean

.PHONY: all clean fclean re run e
