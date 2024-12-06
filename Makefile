# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 14:17:16 by tbruha            #+#    #+#              #
#    Updated: 2024/12/06 12:01:03 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
CFLAGS		= -Wall -Wextra -Werror -g -I include -I libft -I . # -I is for path to .h files
RM			= rm -f
CC			= cc
INCLUDE		= -L ./libft -lft # -L is for pathing to libraries. -lft specifies which lib.
MAKEFLAGS	+= --no-print-directory

SRC_S		=	server.c	# src/push_swap.c delete, here just to see how

SRC_C		= 	client.c

OBJ_S		:=	$(SRC_S:%.c=%.o)

OBJ_C		:=	$(SRC_C:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_S) $(OBJ_C)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJ_S) $(INCLUDE) -o server
	@$(CC) $(CFLAGS) $(OBJ_C) $(INCLUDE) -o client
	@echo "server and client created"

server:	$(OBJ_S)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJ_S) $(INCLUDE) -o server

client: $(OBJ_C)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJ_C) $(INCLUDE) -o client

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<	

clean:
	@$(RM) $(OBJ_S) $(OBJ_C)
	@make clean -C libft/
	@echo "minitalk is clean"

fclean:	clean
	@$(RM) server client
	@make fclean -C libft/
	@echo "minitalk is super clean"

re:	fclean all

.PHONY:	all clean fclean re
