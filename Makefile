# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 08:22:33 by nsierra-          #+#    #+#              #
#    Updated: 2014/04/24 04:12:21 by amaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_minishell1
INC_FILES	=	qd_sh.h \
				builtin_cd.h \
				env.h \
				errors.h \
				libft.h
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
				execution.c \
				find_and_exec.c \
				exec_binary_from_path.c \
				ft_pathbuilder.c \
				main.c \
				ft_atoi.c \
				ft_freer.c \
				ft_isvalid.c \
				ft_print.c \
				ft_putchar.c \
				ft_putendl.c \
				ft_sisnum.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strcat.c \
				ft_split.c \
				ft_putstr.c \
				gnl.c
SRC			=	$(addprefix src/, $(SRC_FILES))
INC			=	$(addprefix inc/, $(INC_FILES))
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
CFLAGS		=	-g3 -Wall -Wextra -Werror
LDFLAGS		=	-I./inc/

all:			$(NAME)

$(NAME):		$(INC) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $@

%.o:			%.c
				$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:
