/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 02:20:14 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 19:45:20 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "libft.h"
#include "env.h"
#include "qd_sh.h"
#include "builtin_cd.h"
#include "errors.h"

static int			check_options(char **args, int *option, int *i)
{
	int				j;

	*i = 1;
	while (args[*i]
			&& args[*i][0] == '-' && args[*i][1] != '\0' && args[*i][1] != '-')
	{
		j = 1;
		while (args[*i][j] != '\0')
		{
			if (args[*i][j] == 'p')
				option[print] = 1;
			else if (args[*i][j] == 'l')
				option[long_format] = 1;
			else if (args[*i][j] == 'n')
				option[n] = 1;
			else if (args[*i][j] == 'v')
				option[verbose] = 1;
			else
				return (0);
			++j;
		}
		++*i;
	}
	return (1);
}

static int			valid_path(const char *path)
{
	struct stat		stats;

	if (lstat(path, &stats) == -1)
	{
		if (errno == ENOENT)
			return (ft_print(ERROR(CD, E_PATHNEXISTS), 2, 0));
		else
			return (ft_print(ERROR(CD, E_GENERIC), 2, 0));
	}
	else
	{
		if (S_ISDIR(stats.st_mode))
			return (1);
		else
			return (ft_print(ERROR(CD, E_NODIR), 2, 0));
	}
}

static int			valid_input_or_die(t_env *e, char **args, int *option)
{
	int				i;
	char			*new_arg;

	if (!args)
		return (ft_print(ERROR(CD, E_GENERIC), 2, 0));
	if (!check_options(args, option, &i))
		return (ft_print(ERROR(CD, E_INVALID_OPTION), 2, 0));
	if (args[i] && args[i + 1])
		return (ft_print(ERROR(CD, E_TOO_MANY_ARG), 2, 0));
	if (args[i][0] == '-' && args[i][1] == '\0')
	{
		if (!e->owd && !(new_arg = env_dup_var(e->env, "OLDPWD")))
			return (ft_print(ERROR(CD, E_NO_OWD), 2, 0));
		else
			new_arg = ft_strdup(e->owd);
		free(args[i]);
		args[i] = new_arg;
	}
	if (!valid_path(args[i]))
		return (0);
	return (i);
}

static int			chdir_to_home(t_env *e)
{
	char			*homepath;

	homepath = NULL;
	if (!(homepath = e->home) && !(homepath = env_get_var(e->env, "HOME")))
		return (ft_print(ERROR(CD, E_NOHOME), 2, 0));
	else if (chdir(homepath) < 0)
		return (0);
	return (1);
}

int					builtin_cd(t_env *e, char **args)
{
	int				option[4];
	int				i;
	char			**args_setenv;

	i = 0;
	while (i < 4)
		option[i++] = 0;
	if (env_get_size((const char **)args) == 1 && !chdir_to_home(e))
		return (0);
	else if (env_get_size((const char **)args) != 1
			&& (!(i = valid_input_or_die(e, args, option))
			|| chdir(args[i]) < 0))
		return (0);
	free(e->owd);
	e->owd = e->cwd;
	args_setenv = create_args(3, "setenv", "OLDPWD", e->cwd);
	builtin_setenv(e, args_setenv);
	env_destroy(args_setenv);
	e->cwd = NULL;
	if (!(e->cwd = NULL) && !(e->cwd = getcwd(e->cwd, (size_t)0)))
		ft_print(ERROR(CD, E_CWDBROK), 2, 0);
	args_setenv = create_args(3, "setenv", "PWD", e->cwd);
	builtin_setenv(e, args_setenv);
	env_destroy(args_setenv);
	return (1);
}
