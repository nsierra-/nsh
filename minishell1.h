/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 08:51:20 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 14:56:55 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
# define MINISHELL1_H
# define SUCCESS 1
# define FAIL 0
# define TRUE 1
# define FALSE 0
# define ERROR_MSG_PATH "while trying to open a dir from PATH. Is PATH valid ?"
# define ERROR_MSG_CLDIR ": Unable to close a directory."
# define ERROR_MSG_LIST "while trying to build exec list."
# define D_NAME ft_strdup(ent->d_name)
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>

typedef struct		s_lexec
{
	char			*name;
	char			*path;
	int				x_ok;
	struct s_lexec	*next;
}					t_lexec;

typedef struct		s_env
{
	char			**path;
	char			*pwd;
	char			*usr_input;
	t_lexec			*lexec;
	int				exitflag;
}					t_env;

typedef struct		s_build_tools
{
	DIR				*cur_dir;
	int				i;
	int				j;
	int				no_inc;
}					t_build_tools;

void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_strsplit(char const *s, char c, int start);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char 				*ft_makepath(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					error(int must_exit, char *err_message);
int					get_next_line(int fd, char **line);
int					prompt(t_env *e);
t_lexec				*add(t_env *e, char *name, char *path, int x_ok);

#endif /* !MINISHELL1_H */
