# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 14:32:18 by cbarbier          #+#    #+#              #
#    Updated: 2017/04/27 14:48:37 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECK			= checker
LIB				= libft/libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRCS			= srcs/main.c \
				  srcs/core.c \
				  srcs/brute_force.c \
				  srcs/tool.c \
				  srcs/bf_tool.c \
				  srcs/lst_tool.c \
				  srcs/best_move.c \
				  srcs/merge_list.c \
				  srcs/ps_print.c \
				  srcs/moves.c \
				  srcs/move_ps.c \
				  srcs/move_r.c \
				  srcs/move_rr.c

CHECK_SRCS		= check_srcs/main.c \
				  check_srcs/core.c \
				  check_srcs/moves.c \
				  check_srcs/move_ps.c \
				  check_srcs/move_r.c \
				  check_srcs/move_rr.c

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
	@$(CC) $(CFLAGS) -o $(CHECK) $(CHECK_OBJS) -Llibft -lft 
	@echo "CHECKER BUILT\t\t\033[0;32m✓\033[0m"

clean:
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(CHECK_OBJS)
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(CHECK)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
