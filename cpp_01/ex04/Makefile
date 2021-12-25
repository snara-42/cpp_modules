# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara </var/mail/snara>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:28:17 by snara             #+#    #+#              #
#    Updated: 2021/11/11 22:19:44 by subaru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= replace
SRCS 	:= Replace.cpp main.cpp

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
	$(RM) *.replace

.PHONY	: fclean
fclean	: clean ## Delete objects and executable
	$(RM) $(NAME)

.PHONY	: re
re		: fclean all ## Rebuild executable

.PHONY	: test
test	: debug ## Run tests
	./$(NAME) 
	@echo
	./$(NAME) nofile no yes
	@echo
	./$(NAME) Makefile "" "??"
	@echo
	./$(NAME) Makefile $$')\n' "" ; mv Makefile.replace Makefile_1.replace; sed -e ':a' -e N -e '$$!ba' -e 's/)\n//g' Makefile | diff -u - Makefile_1.replace && echo ok; :
	@echo
	./$(NAME) Makefile : SEGV ; mv Makefile.replace Makefile_2.replace ; ./$(NAME) Makefile_2.replace .PHONY ';P' ; sed -e 's/:/SEGV/g' -e 's/.PHONY/;P/g' Makefile | diff -u - Makefile_2.replace.replace && echo ok; :
	@echo
	getconf INT_MAX | ./replace - 2 m | ./replace - 14 4rs |./replace - 4 e | ./replace - 836 nn | ./replace - 7 ''

.PHONY	: help
help	: ## Show this message
	@echo "Target lists:"
	@grep -E '^[a-zA-Z_-]+\t*:.*?## .*$$' Makefile | awk 'BEGIN {FS = "\t*:.*?## "}; {printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2}'

