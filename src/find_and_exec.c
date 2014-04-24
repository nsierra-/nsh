/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:55:18 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/24 03:45:11 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"
#include "env.h"
#include "qd_sh.h"

static int			exec_builtin(t_env *e, char **usr_input)
{
	if (ft_strcmp(usr_input[0], "cd") == 0)
		return (builtin_cd(e, usr_input));
	else if (ft_strcmp(usr_input[0], "env") == 0)
		return (builtin_env(e, usr_input));
	else if (ft_strcmp(usr_input[0], "setenv") == 0)
		return (builtin_setenv(e, usr_input));
	else if (ft_strcmp(usr_input[0], "unsetenv") == 0)
		return (builtin_unsetenv(e, usr_input));
	else if (ft_strcmp(usr_input[0], "exit") == 0)
		return (builtin_exit(e, usr_input));
	else
		return (42);
}

int					find_and_exec(t_env *e, char **usr_input)
{
	int				ret;
	int				not_found;

	not_found = 0;
	ret = exec_builtin(e, usr_input);
	if (ret != 42)
		return (ret);
	return (exec_binary_from_path(e->path, e->env, usr_input, &not_found));
}
