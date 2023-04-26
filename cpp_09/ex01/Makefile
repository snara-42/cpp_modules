# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2023/04/22 23:37:57 by subaru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= RPN
SRCS 	:= main.cpp RPN.cpp

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
debug	: CXXFLAGS += -g -fsanitize=address -fsanitize=undefined ## Add debug options
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
	./$(NAME) "0 a"
	./$(NAME) "4 2"
	./$(NAME) "+"
	./$(NAME) "0"
	./$(NAME) "4 2 +"
	./$(NAME) "4 2 -"
	./$(NAME) "4 2 *"
	./$(NAME) "4 2 /"
	./$(NAME) "4 2 %"
	./$(NAME) "8888888888*********1-2*1+" #INT_MAX
	./$(NAME) "8888888888*********1-2*1+ 1+" #INT_MAX+1
	./$(NAME) "8888888888*********02-*" #INT_MIN
	./$(NAME) "8888888888*********02-* 1-" #INT_MIN-1
	./$(NAME) "8888888888*********02-* 01-*" #-INT_MIN
	./$(NAME) "8888888888*********2*" #2147483648
	./$(NAME) "8888888888*********1-2*1+ 8888888888*********1-2*1+  " #INT_MAX,INT_MAX
	./$(NAME) "8888888888*********1-2*1+ 8888888888*********1-2*1+ +" #INT_MAX+INT_MAX
	./$(NAME) "8888888888*********1-2*1+ 8888888888*********1-2*1+ -" #INT_MAX-INT_MAX
	./$(NAME) "8888888888*********1-2*1+ 8888888888*********1-2*1+ *" #INT_MAX*INT_MAX
	./$(NAME) "8888888888*********1-2*1+ 8888888888*********1-2*1+ /" #INT_MAX/INT_MAX
	./$(NAME) "8888888888*********02-* 8888888888*********02-* +" #INT_MIN+INT_MIN
	./$(NAME) "8888888888*********02-* 8888888888*********02-* -" #INT_MIN-INT_MIN
	./$(NAME) "8888888888*********02-* 8888888888*********02-* *" #INT_MIN*INT_MIN
	./$(NAME) "8888888888*********02-* 8888888888*********02-* /" #INT_MIN/INT_MIN
	./$(NAME) "8888888888*********02-* 8888888888*********02-* %" #INT_MIN%INT_MIN
	./$(NAME) "8888888888*********02-* 0/" #/0
	./$(NAME) "8888888888*********02-* 0%" #%0
	./$(NAME) "8888888888*********02-* 01-/" #INT_MIN/-1
	./$(NAME) "8888888888*********02-* 01-%" #INT_MIN%-1

-include $(DEPS)

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'



