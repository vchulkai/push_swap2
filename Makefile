# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:51:37 by vchulkai          #+#    #+#              #
#    Updated: 2023/06/19 16:12:45 by vchulkai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = CC

CFLAGS = -Wall -Wextra -Werror

SRC = 	lst_util1.c\
		lst_util2.c\
		lst_util3.c\
		main.c\
		push_swap.c\
		push_swap_util.c\
		util.c\
		instruction.c\
		instruction2.c\

OBJS =  lst_util1.o\
		lst_util2.o\
		lst_util3.o\
		main.o\
		push_swap.o\
		push_swap_util.o\
		util.o\
		instruction.o\
		instruction2.o\

INC = push_swap.h

%o: %c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Ready to swap!"

clean:
	$(RM) $(OBJS)
	@echo "yep, cleaned"

fclean: clean
	$(RM) $(NAME)
	@echo "tidy -- totally cleaned!"

re:	fclean all

.PHONY: all clean fclean re
