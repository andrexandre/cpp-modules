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
NAME		:= btc

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

VARS := input.txt

run: re
	@./$(NAME) $(VARS)

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(VARS)

e: fclean
	@rm -f data.csv input.txt input.csv

data:
	@wget -q https://cdn.intra.42.fr/document/document/25699/cpp_09.tgz
	@tar -xzf cpp_09.tgz
	@mv cpp_09/data.csv .
	@rm -rf cpp_09.tgz cpp_09
	@echo Downloaded data.csv from intra

input:
	@printf "date | value\n\
	2011-01-03 | 3\n\
	2011-01-03 | 2\n\
	2011-01-03 | 1\n\
	2011-01-03 | 1.2\n\
	2011-01-09 | 1\n\
	2012-01-11 | -1\n\
	2001-42-42\n\
	2012-01-11 | 1\n\
	2012-01-11 | 2147483648" > input.txt
	@echo Created input.txt file

file:
	@wget -O input.csv -q https://cdn.intra.42.fr/document/document/20226/input.csv
	@echo Downloaded input.csv from intra

eval: data input file
	./$(NAME) input.txt
	@echo
	./$(NAME) input.csv

check:
	@grep -r -o -w '\w*alloc\w*' ..
	@grep -r -o -w '\w*printf\w*' ..
	@grep -r -o -w '\w*free\w*' ..
	@grep -r -o -w '\w*using namespace\w*' ..
	@grep -r -o -w '\w*friend\w*' ..
	@echo
	@grep -r -o -w '\w*CXXFLAGS	:= -Wall -Wextra -Werror -g -std=c++98\w*' ..

.PHONY: all clean fclean re run e data input file eval check
