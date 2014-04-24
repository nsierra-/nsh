/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 04:30:01 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 20:22:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <paths.h>
#include <stdlib.h>
#include "libft.h"
#include "errors.h"
#include "env.h"
#include "qd_sh.h"

static int			valid_input_or_die(t_env *e, const char **args)
{
	size_t			args_size;

	args_size = env_get_size(args);
	if (args_size == 0)
		return (ft_print(ERROR(SETENV, E_INPUT), 2, 0));
	else if (args_size == 1)
	{
		env_print((const char **)e->env);
		return (0);
	}
	else if (args_size == 2)
		return (ft_print(ERROR(SETENV, E_NOT_ENOUGH_ARG), 2, 0));
	else if (args_size > 3)
		return (ft_print(ERROR(SETENV, E_TOO_MANY_ARG), 2, 0));
	else
		return (1);
}

static void			update_shell(t_env *e, char **args)
{
	if (!ft_strcmp("PATH", args[1]))
	{
		if (e->path)
			free(e->path);
		if (!(e->path = ft_strdup(args[2])))
			e->path = ft_strdup(_PATH_STDPATH);
	}
	else if (!ft_strcmp("TERM", args[1]))
	{
		if (e->term)
			free(e->term);
		if (!(e->term = ft_strdup(args[2])))
			e->term = NULL;
	}
	else if (!ft_strcmp("HOME", args[1]))
	{
		if (e->home)
			free(e->home);
		if (!(e->home = ft_strdup(args[2])))
			e->home = NULL;
	}
}

int					builtin_setenv(t_env *e, char **args)
{
	if (!valid_input_or_die(e, (const char **)args))
		return (0);
	if (env_is_set((const char **)e->env, (const char *)args[1]) < 0)
	{
		if (!(e->env = env_add_var(e->env, args[1], args[2])))
			return (ft_print(ERROR(SETENV, E_GENERIC), 2, 0));
		update_shell(e, args);
		return (1);
	}
	else if (env_update_var(e->env, args[1], args[2]) < 0)
		return (ft_print(ERROR(SETENV, E_GENERIC), 2, 0));
	update_shell(e, args);
	return (1);
}
