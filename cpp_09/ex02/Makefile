# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2023/04/23 03:28:24 by subaru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= PmergeMe
SRCS 	:= main.cpp PmergeMe.cpp Timer.cpp

TESTFILE:= 
INCS	:= -I./
OBJDIR	:= ./objs
OBJS 	:= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS 	:= $(OBJS:.o=.d)

CXX		:= c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP $(INCS) 
RM		:= rm -f

.PHONY	: all
all		: $(NAME) ## Build executable

$(NAME)	: $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o	: %.cpp
	$(CXX) $(CXXFLAGS) -o $@  -c $<

$(OBJDIR):
	mkdir -p $@

.PHONY	: leaks 
leaks	: CXXFLAGS += -D LEAKS=1 ## Add leak check options
leaks	: re
	./$(NAME)

.PHONY	: debug
debug	: CXXFLAGS = -Wall -Wextra -std=c++98 -pedantic -MMD -MP $(INCS) -g -fsanitize=address -fsanitize=undefined ## Add debug options
debug	: re

.PHONY	: clean
clean	: ## Delete objects and dependencies
	$(RM) $(OBJS) $(DEPS) $(TESTFILE)

.PHONY	: fclean
fclean	: clean ## Delete objects and executable
	$(RM) $(NAME)

.PHONY	: re
re		: fclean all ## Rebuild executable

.PHONY	: test
test	: debug ## Run tests
	./$(NAME)
	./$(NAME) ""
	./$(NAME) "0a"
	./$(NAME) "-1"
	./$(NAME) "-"
	./$(NAME) "+0"
	./$(NAME) " 0"
	./$(NAME) "-0"
	./$(NAME) 2147483648
	./$(NAME) 4294967295
	./$(NAME) 4294967296
	./$(NAME) 4 2 4 2
	./$(NAME) `ruby -e 'print (1..10).to_a.shuffle * " "'`
	./$(NAME) `ruby -e 'print (1..100).to_a.shuffle * " "'`
	./$(NAME) `ruby -e 'print (1..1000).to_a.shuffle * " "'`
	./$(NAME) `ruby -e 'print (1..10000).to_a.shuffle * " "'`

-include $(DEPS)

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



