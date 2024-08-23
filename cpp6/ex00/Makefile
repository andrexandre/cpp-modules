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
NAME		:= convert

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

e: fclean

# the: tr -d '\r' is to convert a CR+LF(Windows) to a LF(Linux) line ending
test: $(NAME)
	@wget -qO- https://pastebin.com/raw/JakmLrXc | tr -d '\r' | bash

download:
	@wget -qO tester.sh https://pastebin.com/raw/JakmLrXc
	@cat tester.sh | tr -d '\r' > temp | mv temp tester.sh
	@chmod 777 tester.sh

check:
	@grep -r -o -w '\w*alloc\w*' ..
	@grep -r -o -w '\w*printf\w*' ..
	@grep -r -o -w '\w*free\w*' ..
	@grep -r -o -w '\w*using namespace\w*' ..
	@grep -r -o -w '\w*friend\w*' ..
	@echo
	@grep -r -o -w '\w*CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98\w*' ..

.PHONY: all clean fclean re run e
