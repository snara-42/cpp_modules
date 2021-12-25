# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2021/11/12 15:48:15 by subaru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= exe
SRCS 	:= Fixed.cpp main.cpp

TESTFILE:= test.txt

INCS	:= -I./
OBJS 	:= $(SRCS:.cpp=.o)
DEPS 	:= $(SRCS:.cpp=.d)

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP $(INCS)
RM		:= rm -f

.PHONY	: all
all		: $(NAME) ## Build executable

-include $(DEPS)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY	: debug
debug	: CXXFLAGS += -g -fsanitize=address ## Add debug options
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
	@echo 'Default constructor called\nCopy constructor called\nAssignation operator called\ngetRawBits member function called\nDefault constructor called\nAssignation operator called\ngetRawBits member function called\ngetRawBits member function called\n0\ngetRawBits member function called\n0\ngetRawBits member function called\n0\nDestructor called\nDestructor called\nDestructor called' > $(TESTFILE)
	./$(NAME) | diff -u - $(TESTFILE) && echo ok ; :

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



