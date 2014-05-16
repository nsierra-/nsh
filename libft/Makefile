# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/15 02:46:59 by nsierra-          #+#    #+#              #
#    Updated: 2014/05/16 05:07:08 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
LIBNAME		=	ft

INC			=	libft.h

SRC			=	ft_atoi.c \
				ft_freer.c \
				ft_isvalid.c \
				ft_pathbuilder.c \
				ft_print.c \
				ft_putchar.c \
				ft_putendl.c \
				ft_putstr.c \
				ft_sisnum.c \
				ft_split.c \
				ft_strcat.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strclean.c

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-O2 -Wall -Wextra -Werror

LDFLAGS		=	-I./

all:		$(NAME)

$(NAME):	$(INC)
	$(CC) $(LDFLAGS) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:			fclean all
