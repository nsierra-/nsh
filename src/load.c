/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 00:36:55 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/27 07:06:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <paths.h>
#include "qd_sh.h"
#include "errors.h"
#include "libft.h"
#include "env.h"

/*
**
** EMPTY ENVIRON MODE (A.K.A "SURVIVAL MODE")
** +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
**
** Manually sets a basic env variable into e->env (using builtin_setenv() and
** create_args() (see section "NORMAL MODE" below)) and sets necessaries shell
** variables.
** Other shell variables may be updated by user (such as owd and home), and
** they remain NULL until so.
**
*/
static int		empty_environ_mode(t_env *e)
{
	char		**tmp;

	if (!(e->env = NULL)
			&& !(e->env = malloc(sizeof(char *) * 1)))
		return (ft_print(ERROR(SH, E_ENVFAIL), 2, 0));
	e->env[0] = NULL;
	if (!(tmp = create_args(3, "setenv", "PATH", _PATH_STDPATH))
			|| !(e->path = ft_strdup(_PATH_STDPATH)))
		ft_print(ERROR(SH, E_PATHBROK), 2, 0);
	builtin_setenv(e, tmp);
	env_destroy(tmp);
	e->cwd = getcwd(e->cwd, (size_t)0);
	if ((!(tmp = create_args(3, "setenv", "PWD", e->cwd))))
		ft_print(ERROR(SH, E_CWDBROK), 2, 0);
	builtin_setenv(e, tmp);
	env_destroy(tmp);
	if (!(tmp = create_args(3, "setenv", "TERM", "dumb"))
			|| !(e->term = ft_strdup("dumb")))
		ft_print(ERROR(SH, E_PATHBROK), 2, 0);
	builtin_setenv(e, tmp);
	env_destroy(tmp);
	tmp = NULL;
	set_extra_infos(e);
	return (1);
}

/*
**
** NORMAL MODE
** +=+=+=+=+=+
**
** normal_load_mode() and manage_cpy() are copying environ into e->env and
** set shell variables home, path, owd, term and cwd.
** By the way, cwd is set using getcwd(), but the value of PWD will not be
** updated (if user is a moron, user is a moron).
** Note that a check is made for presence of PATH and TERM, and depending
** on that tries to set it manually.
** As we are using builtin_setenv() to set manually those variables, we must
** build an array of strings, since builtin_setenv() requires a (char **)
** as its second parameter.
**
*/
static int		manage_cpy(t_env *e, int env_size, t_bool *tok, t_bool *pok)
{
	if (is_var("HOME", e->original_env[env_size])
			&& !(e->home = ft_strdup(e->original_env[env_size] + 5)))
		return (ft_print(ERROR(SH, E_HOMEBROK), 2, 1));
	else if (is_var("PATH", e->original_env[env_size])
			&& (e->path = ft_strdup(e->original_env[env_size] + 5)))
		*pok = true;
	else if (is_var("OLDPWD", e->original_env[env_size])
			&& !(e->owd = ft_strdup(e->original_env[env_size] + 7)))
		return (ft_print(ERROR(SH, E_OWDBROK), 2, 1));
	else if (is_var("TERM", e->original_env[env_size])
			&& (e->term = ft_strdup(e->original_env[env_size] + 5)))
		*tok = true;
	if (!(e->env[env_size] = ft_strdup(e->original_env[env_size])))
		return (ft_print(ERROR(SH, E_ENVBROK), 2, 0));
	return (1);
}

static void		normal_load_mode(t_env *e, int env_size)
{
	char		**tmp;
	t_bool		term_ok;
	t_bool		path_ok;

	term_ok = false;
	path_ok = false;
	tmp = NULL;
	while (env_size >= 0)
	{
		if (!manage_cpy(e, env_size--, &term_ok, &path_ok))
			break ;
	}
	if (term_ok == false && (tmp = create_args(3, "setenv", "TERM", "dumb")))
	{
		builtin_setenv(e, tmp);
		env_destroy(tmp);
	}
	if (path_ok == false
			&& (tmp = create_args(3, "setenv", "PATH", _PATH_STDPATH)))
	{
		builtin_setenv(e, tmp);
		env_destroy(tmp);
	}
	e->cwd = NULL;
	e->cwd = getcwd(e->cwd, (size_t)0);
}

static void		set_prompt_str(t_env *e)
{
	t_utsname	uts_name;
	char		*tmp_hostval;
	int			i;

	i = 0;
	if (env_is_set((const char **)e->env, "HOST") < 0)
	{
		if (!uname(&uts_name))
			env_setenv_var(e, "HOST", uts_name.nodename);
	}

	ft_strcat(e->prompt_str, env_get_var(e->env, "USER"));
	ft_strcat(e->prompt_str, "@");
	tmp_hostval = env_dup_var(e->env, "HOST");
	while (tmp_hostval && (tmp_hostval[i] != '.' && tmp_hostval[i] != '\0'))
		++i;
	if (tmp_hostval && tmp_hostval[i] == '.')
		tmp_hostval[i] = '\0';
	ft_strcat(e->prompt_str, tmp_hostval);
	free(tmp_hostval);
	ft_strcat(e->prompt_str, " $ ");
}

/*
**
** ENTRY POINT
** +=+=+=+=+=+
**
** Depending on the state of environ :
**		- Empty : load basic infos and set a basic env variable containing
**					PATH, PWD, HOST, USER, LOGNAME and SHELL
**		- Full (already contaning an env variable) : contents of environ are
**					copied into e->env and shell variables are set.
**
*/
int				load_shell_vars(t_env *e)
{
	size_t		env_size;

	if (!*e->original_env)
	{
		if (!empty_environ_mode(e))
			return (0);
	}
	else
	{
		env_size = env_get_size(e->original_env);
		if (!(e->env = NULL) && !(e->env = malloc(sizeof(char *) * env_size + 1)))
			return (ft_print(ERROR(SH, E_ENVFAIL), 2, 0));
		e->env[env_size--] = NULL;
		normal_load_mode(e, (int)env_size);
	}
	set_prompt_str(e);
	return (1);
}
