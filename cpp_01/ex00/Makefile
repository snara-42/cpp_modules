# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2021/11/11 19:39:08 by subaru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= zombie
SRCS 	:= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

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
	$(RM) $(OBJS) $(DEPS)

.PHONY	: fclean
fclean	: clean ## Delete objects and executable
	$(RM) $(NAME)

.PHONY	: re
re		: fclean all ## Rebuild executable

.PHONY	: test
test	: debug ## Run tests
	./$(NAME)

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



