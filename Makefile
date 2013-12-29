# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 20:50:12 by nsierra-          #+#    #+#              #
#    Updated: 2013/12/29 11:49:35 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

SRC = ft_putstr.c \
	  ft_strcmp.c \
	  gnl.c \
	  main.c \
	  ft_strsplit.c \
	  prompt.c \
	  error.c \
	  ft_makepath.c \
	  exec_list.c \
	  ft_strdup.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic -g3

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o:%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

test: fclean all

re: fclean all

.PHONY: compile_lib
