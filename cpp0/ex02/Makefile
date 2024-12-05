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

VARS := > main.log

tests.cpp:
	wget -q https://cdn.intra.42.fr/document/document/27912/tests.cpp

Account.hpp:
	wget -q https://cdn.intra.42.fr/document/document/27910/Account.hpp

19920104_091532.log:
	wget -q https://cdn.intra.42.fr/document/document/27911/19920104_091532.log

files: tests.cpp Account.hpp 19920104_091532.log

rmfiles:
	rm -f tests.cpp Account.hpp 19920104_091532.log main.log

run: re
	@./$(NAME) $(VARS)

diff: run
	@echo remove the time from the logs so it can be diffed
	@sleep 2
	diff main.log 19920104_091532.log

v: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(VARS)

e: fclean

.PHONY: all clean fclean re run e
