# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 10:13:35 by vlaroque          #+#    #+#              #
#    Updated: 2018/12/14 11:12:39 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft/includes/
SRC = fillit.c verify_n_register.c tetrimino.c position.c solution.c general.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		make -C libft

clean :
	rm -Rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -Rf $(NAME)
	make -C libft fclean

.PHONY : clean fclean

re :
	@$(MAKE) fclean
	@$(MAKE) all