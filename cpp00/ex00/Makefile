# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2021/11/04 16:38:07 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= megaphone
SRCS 	:= megaphone.cpp
INCS	:= -I./
OBJS 	:= $(SRCS:.cpp=.o)
DEPS 	:= $(SRCS:.cpp=.d)

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -MMD -MP
RM		:= rm -f

.PHONY	: all
all		: $(NAME) ## Build executable

-include $(DEPS)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o $(NAME) $(OBJS)

.PHONY	: clean
clean	: ## Delete objects
	$(RM) $(OBJS) $(DEPS)

.PHONY	: fclean
fclean	: clean ## Delete objects and executable
	$(RM) $(NAME)

.PHONY	: re
re		: fclean all ## Rebuild executable

.PHONY	: test
test	: $(NAME) ## Run tests
	./$(NAME)
	./$(NAME) ''
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



