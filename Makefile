# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/03/23 13:45:25 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECK			= checker
LIB				= libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRCS			= srcs/main.c
CHECK_SRCS		= check_srcs/main.c

OBJS			= $(SRCS:.c=.o)
CHECK_OBJS		= $(CHECK_SRCS:.c=.o)

all: $(NAME) $(CHECK)


%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft 
	@echo "PUSH_SWAP BUILT\t\t\033[0;32m✓\033[0m"

$(LIB):
	@make -C libft

$(CHECK): $(LIB) $(CHECK_OBJS)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(CHECK_OBJS) -Llibft -lft 
	@echo "CHECKER BUILT\t\t\033[0;32m✓\033[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(CHECK_OBJS)
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(CHECKER)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
