/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qd_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:03:35 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/16 06:28:23 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QD_SH_H
# define QD_SH_H
# define BASIC_ENV_SIZE 3
# define QTY_SHELL_VAR 5
# define PROMPT_MAX_SIZE 40
# define MAX_INPUT_SIZE 1024
# define S_DIRENT struct dirent

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef struct		s_env
{
	const char		**original_env;
	char			**env;
	char			*path;
	char			*cwd;
	char			*owd;
	char			*home;
	char			*term;
	char			prompt_str[PROMPT_MAX_SIZE];
}					t_env;

/*
** Makes (at most) two arguments, which will respectively be the name and the
** value of a new variable set into env. If no argument is given, prints the
** current env. Returns 0 in case of failure, and 1 on success.
*/
int					builtin_setenv(t_env *e, char **args);
/*
** Takes n arguments and deletes any argument corresponding to an env var.
** Returns 0 on failure, 1 on success.
*/
int					builtin_unsetenv(t_env *e, char **args);
/*
** echo, implemented as it is here, MUST recieved an already formatted string,
** i.e. escapes sequences are converted into corresponding characters, and
** all strings are valid. It's not the role of echo to do such a conversion
** (unless we decide to do it like this (and this is the case in some shells))
*/
int					builtin_echo(t_env *e, char **args);
/*
** Frees all shell variables, env, and returns what user decided.
*/
int					builtin_exit(t_env *e, char **args);
int					builtin_env(t_env *e, char **args);
int					builtin_cd(t_env *e, char **args);
/*
** In case we have an empty env, LOGNAME, USER, SHELL, HOME, HOST and MACHTYPE
** env variable are set manually with set_extra_infos()
*/
void				set_extra_infos(t_env *e);
/*
** First function to be called. Will copy environ or set manually important
** env variables.
*/
int					load_shell_vars(t_env *e);
int					execution(t_env *e);
int					find_and_exec(t_env *e, char **usr_input);
int					exec_binary_from_path(char *path, char **env, char **argv,
											int *not_found);
int					ft_print(const char *str, int fd, int ret);
char				**prompt(t_env *e, unsigned int *stop);

#endif
