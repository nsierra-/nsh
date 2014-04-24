/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 04:42:20 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 18:22:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "env.h"
#include "qd_sh.h"
#include "libft.h"

void					env_setenv_var(t_env *e, const char *var, char *value)
{
	char				**args;

	if (!(args = create_args(3, "setenv", var, value)))
		return ;
	builtin_setenv(e, args);
	env_destroy(args);
}

char					**create_args(size_t size, ...)
{
	va_list	ap;
	char	**new_arg_array;
	size_t	i;

	va_start(ap, size);
	if (!(new_arg_array = NULL)
		&& !(new_arg_array = malloc(sizeof(char *) * size + 1)))
		return (NULL);
	new_arg_array[size] = NULL;
	i = 0;
	while (i < size)
		new_arg_array[i++] = ft_strdup(va_arg(ap, char *));
	va_end(ap);
	return (new_arg_array);
}

char					*env_get_var(char **env, const char *var_asked)
{
	int		i;

	if ((i = env_is_set((const char **)env, var_asked)) < 0)
		return (NULL);
	return (env[i] + ft_strlen(var_asked) + 1);
}

char					*env_dup_var(char **env, const char *var_asked)
{
	return (ft_strdup(env_get_var(env, var_asked)));
}
