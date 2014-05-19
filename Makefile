# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 08:22:33 by nsierra-          #+#    #+#              #
#    Updated: 2014/05/19 08:55:18 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_minishell2

INC_FILES	=	qd_sh.h \
				builtin_cd.h \
				env.h \
				errors.h \
				gnl.h \
				singleton.h \
				parser.h \
				tokens.h

SRC_FILES	=	builtin_cd.c \
				builtin_env.c \
				builtin_echo.c \
				builtin_exit.c \
				builtin_setenv.c \
				builtin_unsetenv.c \
				env1.c \
				env2.c \
				env3.c \
				load.c \
				set_extra_infos.c \
				main_loop.c \
				find_and_exec.c \
				exec_binary_from_path.c \
				lexer.c \
				parser.c \
				parser_validations.c \
				singleton_tmptab.c \
				main.c \
				gnl.c

SRC			=	$(addprefix src/, $(SRC_FILES))
INC			=	$(addprefix inc/, $(INC_FILES))
OBJ			=	$(SRC:.c=.o)

CC			=	gcc
MAKE		=	make

CFLAGS		=	-g3 -Wall -Wextra -Werror
IFLAGS		=	-I./inc/ -I./libft/
LDFLAGS		=	-L./libft/ -lft

all:			$(NAME)

$(NAME):		$(INC) $(OBJ)
				$(MAKE) -C libft/
				$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $@

%.o:			%.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
				$(MAKE) -C libft/ clean
				rm -rf $(OBJ)

fclean:			clean
				$(MAKE) -C libft/ fclean
				rm -f $(NAME)

re:				fclean all

.PHONY:
