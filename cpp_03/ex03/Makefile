# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2021/11/15 18:10:42 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= exe
SRCS 	:= ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp ScavTrap.cpp main.cpp

TESTFILE:= 
INCS	:= -I./
ODJDIR	:= ./objs
OBJS 	:= $(SRCS:%.cpp=$(ODJDIR)/%.o)
DEPS 	:= $(OBJS:.o=.d)

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP $(INCS) -Wshadow
RM		:= rm -f

.PHONY	: all
all		: $(NAME) ## Build executable

$(NAME)	: $(ODJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(ODJDIR)/%.o	: %.cpp
	$(CXX) $(CXXFLAGS) -o $@  -c $<

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

$(ODJDIR):
	mkdir -p $@

-include $(DEPS)

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



