# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2021/11/22 19:38:45 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= exe
SRCS 	:= main.cpp Fixed.cpp

TESTFILE:= 
INCS	:= -I./
OBJDIR	:= ./objs
OBJS 	:= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS 	:= $(OBJS:.o=.d)

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP $(INCS) 
RM		:= rm -f

.PHONY	: all
all		: $(NAME) ## Build executable

$(NAME)	: $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o	: %.cpp
	$(CXX) $(CXXFLAGS) -o $@  -c $<

.PHONY	: leaks 
leaks	: CXXFLAGS += -D LEAKS=1 ## Add leak check options
leas	: re

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

$(OBJDIR):
	mkdir -p $@

-include $(DEPS)

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



